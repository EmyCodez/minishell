/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:12:33 by esimpson          #+#    #+#             */
/*   Updated: 2024/03/26 14:09:22 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

void	test_cmd(t_shell *myshell, int *exit_status)
{
	char	**argv;

	argv = ft_split(myshell->buff, ' ');
	if (ft_strcmpi(argv[0], "echo") == 0)
		echo(argv);
	else if (ft_strcmpi(argv[0], "pwd") == 0)
		pwd(exit_status);
	else if (ft_strcmpi(argv[0], "env") == 0)
		env(myshell);
	else if (ft_strcmpi(argv[0], "export") == 0)
		export(argv, &myshell->env_list, exit_status);
	else if (ft_strcmp(argv[0], "exit") == 0)
		exit_cmd(myshell, exit_status);
	else
		printf("%s: command not found\n", argv[0]);
}
