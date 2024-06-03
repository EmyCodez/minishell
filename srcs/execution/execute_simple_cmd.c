/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:09:13 by emilin            #+#    #+#             */
/*   Updated: 2024/06/03 15:25:21 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reset_stds(int piped)
{
	if (piped)
    	return ;
	// dup2(g_minishell.stdin, 0);
	// dup2(g_minishell.stdout, 1);
}

int	execute_simple_cmd(t_tree_node *node, int piped, t_shell *myshell, int *exit_code)
{
	int		tmp_status;

    tmp_status =0;
	if (!node ->exp_args)
	{
		// tmp_status = ft_check_redirection(node);
		return (reset_stds(piped), (tmp_status && ERR_GENERAL));
	}
	else if (chk_builtin((node -> exp_args)[0]))
		printf("\n command =%s exit_code=%d \n",myshell->buff,*exit_code);
	// {
	// 	// tmp_status = ft_check_redirection(node);
	// //  if (tmp_status != 0)
	// // 	return (reset_stds(piped), ERR_GENERAL);
	// tmp_status = execute_builtin(&node->args,exit_code,myshell);
	// return (reset_stds(piped), tmp_status);
    // }
	//else
        return(1); // 	return (ft_exec_child(node));    
}
