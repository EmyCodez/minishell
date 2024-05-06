/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:04:16 by emilin            #+#    #+#             */
/*   Updated: 2024/05/06 15:04:03 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree_node	*find_term(t_token **current_token, unsigned int *parse_error)
{
	t_tree_node	*node;

	if (parse_error)
		return (NULL);
	if (is_binary_operator(*current_token)
		|| (*current_token)->tk_type == TK_CLOSE_PAR)
		return (set_parse_error(parse_error, ERR_SYNTAX), NULL);
	if ((*current_token)->tk_type == TK_OPEN_PAR)
	{
		(*current_token) = (*current_token)->next;
		node = find_expression(0, current_token, parse_error);
		if (!node)
			return (set_parse_error(parse_error, ERR_MEMORY), NULL);
		if (!(*current_token) || (*current_token)->tk_type != TK_CLOSE_PAR)
			return (set_parse_error(parse_error, ERR_SYNTAX), node);
		(*current_token) = (*current_token)->next; // CLOSE_PARENTHESIS
		return (node);
	}
	else
		return (get_simple_cmd(current_token, parse_error));
}

t_tree_node	*find_expression(int min_precision, t_token **current_token,
		unsigned int *parse_error)
{
	t_tree_node	*left;
	t_tree_node	*right;
	int			nxt_precision;

	if (!*current_token || parse_error)
		return (NULL);
	left = find_term(current_token, parse_error);
	if (!left)
		return (NULL);
	nxt_precision = min_precision + 1;
	right = find_expression(nxt_precision, current_token, parse_error);
	if (!right)
		return (left);
	return (left);
}

t_tree_node	*parser(t_token *token_list)
{
	t_tree_node		*tree;
	t_token			*current_token;
	unsigned int	parse_error;

	parse_error = 0;
	current_token = token_list;
	tree = find_expression(0, &current_token, &parse_error);
	if (current_token)
	{
		set_parse_error(parse_error, ERR_SYNTAX);
		return (tree);
	}
	return (tree);
}
