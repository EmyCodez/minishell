/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:40:15 by emilin            #+#    #+#             */
/*   Updated: 2024/05/20 09:45:27 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

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

int	get_io_list(t_io_node **io_list, unsigned int *parse_error,
		t_token **current_token)
{
	t_token_type	redir_type;
	t_io_node		*tmp_io_node;

	if (*parse_error)
		return (0);
	while (current_token && is_redirect((*current_token)->tk_type))
	{
		redir_type = (*current_token)->tk_type;
		(*current_token) = (*current_token)->next;
		if (!current_token)
			return (set_parse_error(parse_error, ERR_SYNTAX), 0);
		if ((*current_token)->tk_type != TK_IDENTIFIER)
			return (set_parse_error(parse_error, ERR_SYNTAX), 0);
		tmp_io_node = new_io_node(redir_type, (*current_token)->tk_value);
		if (!tmp_io_node)
			return (set_parse_error(parse_error, ERR_MEMORY), 0);
		append_io_node(io_list, tmp_io_node);
		(*current_token) = (*current_token)->next;
	}
	return (1);
}

int	join_args(char **args)
{
	if(!*args)
	return(ft_strdup(""),0);
	return (1);
}

t_tree_node	*get_simple_cmd(t_token **curr_token, unsigned int *parse_error)
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
			if (!get_io_list(&(node->io_list),parse_error,curr_token))
				return (free_ptr(node->args), free_ptr(node), NULL);
		}
	}
	return (node);
}
