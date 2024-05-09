/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:17:40 by emilin            #+#    #+#             */
/*   Updated: 2024/05/09 11:13:10 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clear_io_list(t_io_node **io_list)
{
	t_io_node	*current_io;
	t_io_node	*next_io;

	current_io = *io_list;
	if (!current_io)
		return ;
	while (current_io)
	{
		free_ptr(current_io->value);
		free_2d_array(current_io->exp_value);
		next_io = current_io->next;
		free_ptr(current_io);
		current_io = next_io;
	}
	*io_list = NULL;
}

void	clear_cmd_node(t_tree_node *node)
{
	if (!node)
		return ;
	clear_io_list(&(node->io_list));
	free_ptr(node->args);
	free_2d_array(node->exp_args);
}

static void	clear_child_nodes(t_tree_node *node)
{
	if (!node)
		return ;
	if (node->type == ND_CMD)
		clear_cmd_node(node);
	else
	{
		if (node->left)
			clear_child_nodes(node->left);
		if (node->right)
			clear_child_nodes(node->right);
	}
	free_ptr(node);
}

void	clear_tree(t_tree_node **tree, t_token **token_list)
{
	clear_child_nodes(*tree);
	*tree = NULL;
	free_token_list(token_list);
}
