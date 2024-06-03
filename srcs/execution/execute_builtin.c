/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:14:37 by emilin            #+#    #+#             */
/*   Updated: 2024/06/03 12:47:34 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	exec_builtin(char **args, int *exit_code, t_shell *myshell)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (echo(args),0);
	if (ft_strcmp(args[0], "cd") == 0)
		return(cd(args, exit_code, myshell->env_list), 0);
	if (ft_strcmp(args[0], "env") == 0)
		return (env(myshell),0);
	if (ft_strcmp(args[0], "pwd") == 0)
		return (pwd(exit_code),0);
	if (ft_strcmp(args[0], "export") == 0)
		return (export(args,&myshell->env_list,exit_code), 0);
	if (ft_strcmp(args[0], "unset") == 0)
		return (unset(args,&myshell->env_list,exit_code), 0);
	exit_cmd(args, exit_code);
	return (ERR_GENERAL);
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
