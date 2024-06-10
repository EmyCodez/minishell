/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:21:39 by emilin            #+#    #+#             */
/*   Updated: 2024/06/10 15:03:03 by emilin           ###   ########.fr       */
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

static void
	execute_pipe_child(t_tree_node *node, int pfds[2], int direction, t_shell *myshell)
{
	int	status;

	if (direction == DIR_LEFT)
	{
		close(pfds[0]);
		dup2(pfds[1], STDOUT_FILENO);
		close(pfds[1]);
	}
	else if (direction == DIR_RIGHT)
	{
		close(pfds[1]);
		dup2(pfds[0], STDIN_FILENO);
		close(pfds[0]);
	}
	status = execute_node(node, 1, myshell);
	(clean_shell(myshell), exit(status));
}

static	int	execute_pipeline(t_tree_node *tree, t_shell *myshell)
{
	int	status;
	int	pfds[2];
	int	pid_l;
	int	pid_r;

	myshell->sigint_child = 1;
	pipe(pfds);
	pid_l = fork();
	if (!pid_l)
		execute_pipe_child(tree->left, pfds, DIR_LEFT, myshell);
	else
	{
		pid_r = fork();
		if (!pid_r)
			execute_pipe_child(tree->right, pfds, DIR_RIGHT, myshell);
		else
		{
			(close(pfds[0]), close(pfds[1]),
				waitpid(pid_l, &status, 0), waitpid(pid_r, &status, 0));
			myshell->sigint_child = 0;
			return (get_exit_status(status));
		}
	}
	return (ENO_GENERAL);
}

int	execute_node(t_tree_node *tree, short piped, t_shell *myshell)
{
	if (tree->type == ND_PIPE)
		return (execute_pipeline(tree, myshell));
	else
		return (execute_simple_cmd(tree, piped, myshell));
	return (ENO_GENERAL);
}
