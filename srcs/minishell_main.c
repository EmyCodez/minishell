/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:33:24 by esimpson          #+#    #+#             */
/*   Updated: 2024/05/09 13:12:29 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

static void	init_shell(t_shell *myshell, char **envp, int *exit_code)
{
	*exit_code = 0;
	myshell->env = envp;
	myshell->env_list = NULL;
	myshell->token_lst = NULL;
	init_env_list(envp, &myshell->env_list);
}

static void	command_execution(t_shell *myshell, int *exit_code)
{
	add_history(myshell->buff);
	myshell->token_lst = tokenizer(myshell->buff, exit_code);
	myshell->tree = parser(&myshell->token_lst);
	test_cmd(myshell, exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	myshell;
	int		exit_code;

	(void)argc;
	(void)argv;
	exit_code = 0;
	init_shell(&myshell, envp, &exit_code);
	while (1)
	{
		myshell.buff = readline(PROMPT_MSG);
		if (!myshell.buff)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			free_env_list(myshell.env_list);
			return (exit_code);
		}
		if (!is_valid_input(myshell.buff))
			free_ptr(myshell.buff);
		else
			command_execution(&myshell, &exit_code);
	}
	rl_clear_history();
	free_env_list(myshell.env_list);
	free_token_list(&myshell.token_lst);
	return (exit_code);
}
