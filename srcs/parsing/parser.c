/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:04:16 by emilin            #+#    #+#             */
/*   Updated: 2024/04/27 16:22:50 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree_node	*add_expression(int min_precision, t_token *current_token)
{
	t_tree_node	*left;
	t_tree_node	*right;
	int			nxt_precision;

	if (!current_token)
		return (NULL);
	left = NULL;
	if (!left)
		return (NULL);
	nxt_precision = min_precision + 1;
	right = add_expression(nxt_precision, current_token);
	if (!right)
		return (left);
	return (left);
}

t_tree_node	*parser(t_token *token_list, int *exit_code)
{
	t_tree_node	*tree;
	t_token		*current_token;

	current_token = token_list;
	tree = add_expression(0, current_token);
	if (current_token)
	{
		*exit_code = 2;
		return (NULL);
	}
	return (tree);
}
