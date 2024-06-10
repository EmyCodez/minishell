/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:14:37 by emilin            #+#    #+#             */
/*   Updated: 2024/06/10 13:23:33 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	execute_builtin(char **args, t_shell *myshell)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (echo(args), 0);
	if (ft_strcmp(args[0], "cd") == 0)
		return (cd(args, &myshell->exit_code, myshell->env_list), 0);
	if (ft_strcmp(args[0], "env") == 0)
		return (env(myshell), 0);
	if (ft_strcmp(args[0], "pwd") == 0)
		return (pwd(&myshell->exit_code), 0);
	if (ft_strcmp(args[0], "export") == 0)
		return (export(args, &myshell->env_list, &myshell->exit_code), 0);
	if (ft_strcmp(args[0], "unset") == 0)
		return (unset(args, &myshell->env_list, &myshell->exit_code), 0);
	exit_cmd(args, &myshell->exit_code);
	return (ENO_GENERAL);
}

int	chk_builtin(char *arg)
{
	if (!arg)
		return (0);
	if (!ft_strcmp(arg, "echo")
		|| !ft_strcmp(arg, "cd")
		|| !ft_strcmp(arg, "exit")
		|| !ft_strcmp(arg, "pwd")
		|| !ft_strcmp(arg, "export")
		|| !ft_strcmp(arg, "unset")
		|| !ft_strcmp(arg, "env"))
		return (1);
	return (0);
}
