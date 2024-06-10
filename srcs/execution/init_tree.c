/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:29:09 by emilin            #+#    #+#             */
/*   Updated: 2024/06/10 15:03:03 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static void	heredoc_sigint_handler(int signum)
{
	(void)signum;
	//ft_clean_ms();
	exit(SIGINT);
}

void	ft_heredoc(t_io_node *io, int p[2],  t_shell *myshell)
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
		if (is_delimiter(io->value, line))
			break ;
		if (!*quotes)
			heredoc_expander(line, p[1], myshell);
		else
			{
				ft_putstr_fd(line, p[1]);
				ft_putstr_fd("\n", p[1]);
			}
	}
	clean_shell(myshell);
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

static void	init_leaf(t_tree_node *node, t_shell *myshell)
{
	t_io_node	*io;
	int			p[2];
	int			pid;

	if (node->args)
		 node->exp_args = expand_str(node->args, &myshell->exit_code, &myshell->env_list);
	node->io_list = 0;	 
	io = node->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
		{
			pipe(p);
			myshell->sigint_child = 1;
			pid = (signal(SIGQUIT, SIG_IGN), fork());
			if (!pid)
				ft_heredoc(io, p, myshell);
			if (leave_leaf(p, &pid, myshell))
				return ;
			io->heredoc = p[0];
		}
		else
			io->exp_value = expand_str(io->value, &myshell->exit_code, &myshell->env_list);
		io = io->next;
	}
}

void	init_tree(t_tree_node *node, t_shell *myshell)
{
	if (!node)
		return ;
	if (node->type == ND_PIPE)
	{
		init_tree(node->left, myshell);
		if (!myshell->heredoc_sigint)
			init_tree(node->right, myshell);
	}
	else
		init_leaf(node, myshell);
}
