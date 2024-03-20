/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:07:57 by esimpson          #+#    #+#             */
/*   Updated: 2024/03/19 14:00:12 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

void	free_exit(t_shell *myshell, int *exit_status)
{
	free_ptr(myshell->buff);
	free_env_list(myshell->env_list);
	exit(*exit_status);
}
