/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:07:03 by emilin            #+#    #+#             */
/*   Updated: 2024/05/25 14:28:31 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

t_node_type	get_node_type(t_token_type tkn_type)
{
	if (tkn_type == TK_PIPE)
		return (ND_PIPE);
	return (ND_CMD);
}

t_io_type	get_io_type(t_token_type type)
{
	if (type == TK_LESS)
		return (IO_IN);
	if (type == TK_GREATER)
		return (IO_OUT);
	if (type == TK_DB_LESS)
		return (IO_HEREDOC);
	return (IO_APPEND);
}


t_tree_node	*new_node(t_node_type node_type)
{
	t_tree_node	*new_tree_node;

	new_tree_node = (t_tree_node *)malloc(sizeof(t_tree_node));
	if (!new_tree_node)
		return (NULL);
	new_tree_node->type = node_type;
	new_tree_node->left = NULL;
	new_tree_node->right= NULL;
	return (new_tree_node);
}

t_io_node	*new_io_node(t_token_type type, char *value)
{
	t_io_node	*new_node;

	new_node = (t_io_node *)malloc( sizeof(t_io_node));
	if (!new_node)
		return (NULL);
	new_node->type = get_io_type(type);
	new_node->value = ft_strdup(value);
	if (!new_node->value)
		return (free_ptr(new_node), NULL);
	return (new_node);
}

void	append_io_node(t_io_node **lst, t_io_node *new)
{
	t_io_node	*curr_node;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr_node = *lst;
	while (curr_node && curr_node->next)
		curr_node = curr_node->next;
	curr_node->next = new;
}
