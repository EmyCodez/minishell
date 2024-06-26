/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:07:57 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/10 15:04:38 by emilin           ###   ########.fr       */
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

void	free_2d_array(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free_ptr(arr[i++]);
	free_ptr(arr);
}

void	clean_shell(t_shell *myshell)
{
	garbage_collection(NULL, 1);
	clear_tree(&myshell->tree, &myshell->token_lst);
	free_env_list(myshell->env_list);
	rl_clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, &myshell->og_term);
}
