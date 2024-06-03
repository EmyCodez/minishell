/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:09:46 by emilin            #+#    #+#             */
/*   Updated: 2024/06/03 15:04:18 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

/* Libraries from includes folder */
# include "env.h"
# include "parsing.h"
# include "tokenizer.h"

typedef struct s_shell
{
	char		*buff;
	char		**env;
	t_env		*env_list;
	t_token		*token_lst;
	t_token		*curr_token;
	t_tree_node	*tree;
	short		heredoc_sigint;
	short		sigint_child;
}				t_shell;

/*---parse_error.c ----*/

void	handle_parse_error(unsigned int *parse_error,
		t_shell *myshell, int *exit_code);


/* ----- execute.c ---------- */
int execute_node(t_tree_node *tree, short piped, t_shell *myshell, int *exit_code);

/* ----- execute_builtin.c ----- */
int	execute_builtin(char **args, int *exit_code, t_shell *myshell);
int	chk_builtin(char *arg);

/* ---- execute_simple_cmd.c ----*/
int	execute_simple_cmd(t_tree_node *node, int piped, t_shell *myshell, int *exit_code);	

/* -----  init_tree ----- */
void	init_tree(t_tree_node *node, t_shell *myshell, int *exit_code);

#endif