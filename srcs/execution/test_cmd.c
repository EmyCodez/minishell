/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:12:33 by esimpson          #+#    #+#             */
/*   Updated: 2024/03/20 16:33:40 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

void	test_cmd(t_shell *myshell, int *exit_status)
{
	if (ft_strcmp(myshell->buff, "pwd") == 0 || (ft_strcmp(myshell->buff,
				"PWD") == 0))
		pwd(exit_status);
	else if (ft_strcmp(myshell->buff, "env") == 0 || (ft_strcmp(myshell->buff,
				"ENV") == 0))
		env(myshell);
	else
	{
		printf(PROMPT_MSG);
		printf("%s: command not found \n", myshell->buff);
	}
}
