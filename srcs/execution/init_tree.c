/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:29:09 by emilin            #+#    #+#             */
/*   Updated: 2024/06/03 13:16:24 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	heredoc_sigint_handler(int signum)
{
	(void)signum;
	//ft_clean_ms();
	exit(SIGINT);
}

void	ft_heredoc(t_io_node *io, int p[2], int *exit_code)
{
	char	*line;
	char	*quotes;

	signal(SIGINT, heredoc_sigint_handler);
	quotes = io->value;
	while (*quotes && *quotes != '"' && *quotes != '\'')
		quotes++;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		// 	if (is_delimiter(io->value, line))
		// 		break ;
			if (!*quotes)
				heredoc_expander(line, p[1],exit_code);
		// 	else
		// 	{
		// 		ft_putstr_fd(line, p[1]);
		// 		ft_putstr_fd("\n", p[1]);
		// 	}
	}
	//ft_clean_ms();
	exit(0);
}

static int	leave_leaf(int p[2], int *pid, t_shell *myshell)
{
	waitpid(*pid, pid, 0);
	signal(SIGQUIT, ft_sigquit_handler);
	myshell->sigint_child = 0;
	close(p[1]);
	if (WIFEXITED(*pid) && WEXITSTATUS(*pid) == SIGINT)
		return (1);
	return (0);
}

static void	init_leaf(t_tree_node *node, t_shell *myshell, int *exit_code)
{
	t_io_node	*io;
	int			p[2];
	int			pid;

	if (node->args)
		node->exp_args = expand_str(node->args, exit_code, &myshell->env_list);
	io = node->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
		{
			pipe(p);
			myshell->sigint_child = 1;
			pid = (signal(SIGQUIT, SIG_IGN), fork());
			if (!pid)
				ft_heredoc(io, p, exit_code);
			if (leave_leaf(p, &pid, myshell))
				return ;
			io->heredoc = p[0];
		}
		else
			io->exp_value = expand_str(node->args, exit_code, &myshell->env_list);
		io = io->next;
	}
}

void	init_tree(t_tree_node *node, t_shell *myshell, int *exit_code)
{
	if (!node)
		return ;
	if (node->type == ND_PIPE)
	{
		init_tree(node->left, myshell, exit_code);
		if (!myshell->heredoc_sigint)
			init_tree(node->right, myshell, exit_code);
	}
	else
		init_leaf(node, myshell, exit_code);
}
