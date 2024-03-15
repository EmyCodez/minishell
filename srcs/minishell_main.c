/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:33:24 by esimpson          #+#    #+#             */
/*   Updated: 2024/03/15 15:35:01 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	char	*buff;
	char	**env_dup;

	(void)argc;
	(void)argv;
	env_dup = arr_2d_dup(envp);
	if (env_dup == NULL)
		return (1);
	if (init_shell(&env_dup[0]))
		return (2);
	while (1)
	{
		buff = readline(PROMPT_MSG);
		if (!buff)
			ft_putstr_fd("exit\n", STDOUT_FILENO);
	}
	// rl_clear_history();
	return (g_exit_code);
}
