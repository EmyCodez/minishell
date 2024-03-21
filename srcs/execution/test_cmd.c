/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:12:33 by esimpson          #+#    #+#             */
/*   Updated: 2024/03/21 15:37:08 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

void	test_cmd(t_shell *myshell, int *exit_status)
{
	if (ft_strcmpi(myshell->buff, "pwd") == 0)
		pwd(exit_status);
	else if (ft_strcmpi(myshell->buff, "env") == 0)
		env(myshell);
}
