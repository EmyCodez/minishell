/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:24:29 by esimpson          #+#    #+#             */
/*   Updated: 2024/03/20 16:35:08 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env(t_shell *myshell)
{
	t_env	*temp;

	temp = myshell->env_list;
	while (temp)
	{
		if (temp->value)
			printf("%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
}
