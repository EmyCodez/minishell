/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:07:17 by lps               #+#    #+#             */
/*   Updated: 2024/03/19 13:36:19 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(int *exit_status)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		printf("%s\n", pwd);
		free(pwd);
	}
	else
	{
		perror("pwd");
		*exit_status = 1;
	}
}
