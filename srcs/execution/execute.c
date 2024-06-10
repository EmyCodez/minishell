/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:21:39 by emilin            #+#    #+#             */
/*   Updated: 2024/06/10 10:34:52 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	get_exit_status(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

int	execute_node(t_tree_node *tree, short piped, t_shell *myshell,
		int *exit_code)
{
	//int status;
	if (!tree)
		return (1);
	execute_simple_cmd(tree, piped, myshell, exit_code);
	return (0);
}
