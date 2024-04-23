/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:36:35 by emilin            #+#    #+#             */
/*   Updated: 2024/04/22 15:25:13 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*new_token_node(char *value, t_token_type type)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->tk_type = type;
	new_token->tk_value = value;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}

void	add_to_token_list(t_token **token_lst, t_token *new_token)
{
	t_token	*temp;

	if (!*token_lst)
	{
		*token_lst = new_token;
		return ;
	}
	temp = *token_lst;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = new_token;
	new_token->prev = temp;
}

void	free_token_list(t_token **token_lst)
{
	t_token	*current;
	t_token	*temp;

	current = *token_lst;
	if (!current)
		return ;
	while (current)
	{
		free_ptr(current->tk_value);
		temp = current->next;
		free_ptr(current);
		current = temp;
	}
	*token_lst = NULL;
}
