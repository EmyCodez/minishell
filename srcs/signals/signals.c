/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:30:33 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/03 13:18:49 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

// static void	sigint_handler(int num, t_shell *myshell)
// {
// 	(void)num;
// 	if (myshell->sigint_child)
// 	{
// 		ft_putstr_fd("\n", 1);
// 		myshell->sigint_child = 0;
// 		myshell->heredoc_sigint = 1;
// 	}
// 	else
// 	{
// 		ft_putstr_fd("\n", 1);
// 		rl_replace_line("", 0);
// 		rl_on_new_line();
// 		rl_redisplay();
// 	}
// }

void	ft_sigquit_handler(int num)
{
	(void)num;
	ft_putstr_fd("Quit: 3\n", 1);
}
