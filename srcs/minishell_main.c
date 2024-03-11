/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:33:24 by esimpson          #+#    #+#             */
/*   Updated: 2024/03/11 14:09:39 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**env_dup;

	(void)argc;
	(void)argv;
	i = 0;
	env_dup = arr_2d_dup(envp);
	if (env_dup == NULL)
		return (1);
	if (init_shell(&env_dup[0]))
		return (2);
	return (g_exit_code);
}
