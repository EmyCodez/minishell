/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:07:03 by emilin            #+#    #+#             */
/*   Updated: 2024/05/06 15:43:11 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree_node	*new_node(t_node_type node_type)
{
	t_tree_node	*new_tree_node;

	new_tree_node = (t_tree_node *)malloc(sizeof(t_tree_node));
	if (!new_tree_node)
		return (NULL);
	new_tree_node->type = node_type;
	return (new_tree_node);
}
