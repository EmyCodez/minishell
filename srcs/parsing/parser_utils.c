/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:40:15 by emilin            #+#    #+#             */
/*   Updated: 2024/05/06 15:45:20 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_binary_operator(t_token *curr_token)
{
	if (!curr_token)
		return (0);
	if (curr_token->tk_type == TK_PIPE)
		return (1);
	return (0);
}

int	is_redirect(t_token_type tkn_type)
{
	if (tkn_type == TK_LESS || tkn_type == TK_GREATER || tkn_type == TK_DB_LESS
		|| tkn_type == TK_DB_GREATER)
		return (1);
	return (0);
}

int	get_io_list(t_io_node **io_list)
{
	return (1);
}

int	join_args(char **args)
{
	return (1);
}

t_tree_node	*get_simple_cmd(t_token **curr_token, int *parse_error)
{
	t_tree_node	*node;

	if (parse_error)
		return (NULL);
	node = new_node(ND_CMD);
	if (!node)
		return (set_parse_error(parse_error, ERR_MEMORY), NULL);
	while (*curr_token && ((*curr_token)->tk_type == TK_IDENTIFIER
			|| is_redirect((*curr_token)->tk_type)))
	{
		if ((*curr_token)->tk_type == TK_IDENTIFIER)
		{
			if (!join_args(&(node->args)))
				return (clear_cmd_node(node), set_parse_error(parse_error,
						ERR_MEMORY), NULL);
		}
		else if (is_redirect((*curr_token)->tk_type))
		{
			if (!get_io_list(&(node->io_list)))
				return (free_ptr(node->args), free_ptr(node), NULL);
		}
	}
	return (node);
}
