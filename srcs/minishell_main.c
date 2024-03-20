/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:33:24 by esimpson          #+#    #+#             */
/*   Updated: 2024/03/20 14:22:47 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

static void	init_shell(t_shell *myshell, char **envp, int *exit_status)
{
	*exit_status = 0;
	myshell->env = envp;
	myshell->env_list = NULL;
	init_env_list(envp, &myshell->env_list);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	myshell;
	int		exit_status;

	(void)argc;
	(void)argv;
	exit_status = 0;
	init_shell(&myshell, envp, &exit_status);
	while (1)
	{
		myshell.buff = readline(PROMPT_MSG);
		if (!myshell.buff)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			free_env_list(myshell.env_list);
			return (exit_status);
		}
		else
			test_cmd(&myshell, &exit_status);
	}
	// rl_clear_history();
	free_env_list(myshell.env_list);
	return (exit_status);
}
