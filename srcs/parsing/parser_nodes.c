/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:07:03 by emilin            #+#    #+#             */
/*   Updated: 2024/05/09 13:29:47 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node_type	get_node_type(t_token_type tkn_type)
{
	if (tkn_type == TK_PIPE)
		return (ND_PIPE);
	return (ND_CMD);
}

t_tree_node	*new_node(t_node_type node_type)
{
	t_tree_node	*new_tree_node;

	new_tree_node = (t_tree_node *)malloc(sizeof(t_tree_node));
	if (!new_tree_node)
		return (NULL);
	new_tree_node->type = node_type;
	return (new_tree_node);
}

void	ft_append_io_node(t_io_node **lst, t_io_node *new)
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
