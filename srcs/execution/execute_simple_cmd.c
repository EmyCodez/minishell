/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:09:13 by emilin            #+#    #+#             */
/*   Updated: 2024/06/10 10:33:39 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	chk_redirection(t_tree_node *node)
{
	t_io_node	*tmp_io;
	int			tmp_status;

	tmp_io = node->io_list;
	while (tmp_io)
	{
		if (tmp_io->type == IO_OUT && ft_out(tmp_io,
				&tmp_status) != EXT_SUCCESS)
			return (tmp_status);
		else if (tmp_io->type == IO_IN && ft_in(tmp_io,
				&tmp_status) != EXT_SUCCESS)
			return (tmp_status);
		else if (tmp_io->type == IO_APPEND && ft_append(tmp_io,
				&tmp_status) != EXT_SUCCESS)
			return (tmp_status);
		else if (tmp_io->type == IO_HEREDOC)
			(dup2(tmp_io->heredoc, 0), close(tmp_io->heredoc));
		tmp_io = tmp_io->next;
	}
	return (EXT_SUCCESS);
}

void	reset_stds(int piped, t_shell *myshell)
{
	if (piped)
		return ;
	dup2(myshell->stdin, 0);
	dup2(myshell->stdout, 1);
}

static int	execute_child(t_tree_node *node, t_shell *myshell)
{
	int	tmp_status;
	int	fork_pid;

	myshell->sigint_child = 1;
	fork_pid = fork();
	if (!fork_pid)
	{
		tmp_status = chk_redirection(node);
		if (tmp_status != EXT_SUCCESS)
		{
			clear_tree(&node, &myshell->token_lst);
			exit(EXT_GENERAL);
		}
	}
	waitpid(fork_pid, &tmp_status, 0);
	myshell->sigint_child = 0;
	return (get_exit_status(tmp_status));
}

int	execute_simple_cmd(t_tree_node *node, int piped, t_shell *myshell,
		int *exit_code)
{
	int	tmp_status;

	if (!node->exp_args)
	{
		tmp_status = chk_redirection(node);
		return (reset_stds(piped, myshell), (tmp_status && EXT_GENERAL));
	}
	else if (chk_builtin((node->exp_args)[0]))
	{
		tmp_status = chk_redirection(node);
		if (tmp_status != EXT_SUCCESS)
			return (reset_stds(piped, myshell), EXT_GENERAL);
		tmp_status = execute_builtin(node->exp_args, exit_code, myshell);
		return (reset_stds(piped, myshell), tmp_status);
	}
	else
		return (execute_child(node, myshell));
}
