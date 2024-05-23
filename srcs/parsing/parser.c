/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:04:16 by emilin            #+#    #+#             */
/*   Updated: 2024/05/23 11:31:57 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree_node	*find_term(t_token **current_token, unsigned int *parse_error,
		t_token **token_list)
{
	t_tree_node	*node;

	if (*parse_error)
		return (NULL);
	if (is_binary_operator(*current_token)
		|| (*current_token)->tk_type == TK_CLOSE_PAR)
		return (set_parse_error(parse_error, ERR_SYNTAX), NULL);
	else if ((*current_token)->tk_type == TK_OPEN_PAR)
	{
		(*current_token) = (*current_token)->next;
		node = find_expression(current_token, parse_error, token_list);
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

t_tree_node	*combine_nodes(t_tree_node *left, t_tree_node *right,
		t_token_type opr, unsigned int *parse_error)
{
	t_tree_node	*node;

	if (*parse_error)
		return (NULL);
	node = new_node(get_node_type(opr));
	if (!node)
		return (set_parse_error(parse_error, ERR_MEMORY), NULL);
	node->left = left;
	node->right = right;
	return (node);
}

t_tree_node	*find_expression(t_token **current_token, unsigned int *parse_error,
		t_token **token_list)
{
	t_tree_node		*left;
	t_tree_node		*right;
	t_token_type	opr;

	if (!*current_token || *parse_error)
		return (NULL);
	left = find_term(current_token, parse_error, token_list);
	if (!left)
		return (NULL);
	while (is_binary_operator(*current_token))
	{
		opr = (*current_token)->tk_type;
		(*current_token) = (*current_token)->next;
		if (!(*current_token))
			return (set_parse_error(parse_error, ERR_SYNTAX), left);
		right = find_expression(current_token, parse_error, token_list);
		if (!right)
			return (left);
		left = combine_nodes(left, right, opr, parse_error);
		if (!left)
			return ((clear_tree(&left, token_list), clear_tree(&right,
						token_list), NULL));
	}
	return (left);
}

t_tree_node	*parser(t_token **token_list,  t_token **current_token, unsigned int	*parse_error)
{
	t_tree_node		*tree;

	tree = find_expression(current_token, parse_error, token_list);
	if (*current_token)
	{
		set_parse_error(parse_error, ERR_SYNTAX);
		return (tree);
	}
	return (tree);
}
