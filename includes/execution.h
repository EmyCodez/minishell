/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:09:46 by emilin            #+#    #+#             */
/*   Updated: 2024/06/10 10:56:55 by esimpson         ###   ########.fr       */
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
	int			stdin;
	int			stdout;
	short		heredoc_sigint;
	short		sigint_child;
}				t_shell;

typedef enum e_err_msg
{
	ERRMSG_CMD_NOT_FOUND,
	ERRMSG_NO_SUCH_FILE,
	ERRMSG_PERM_DENIED,
	ERRMSG_AMBIGUOUS,
	ERRMSG_TOO_MANY_ARGS,
	ERRMSG_NUMERIC_REQUIRED
}				t_err_msg;

typedef enum e_err_no
{
	ENO_SUCCESS,
	ENO_GENERAL,
	ENO_CANT_EXEC = 126,
	ENO_NOT_FOUND,
	ENO_EXEC_255 = 255
}				t_err_no;

typedef struct s_err
{
	t_err_no	no;
	t_err_msg	msg;
	char		*cause;
}				t_err;

typedef struct s_path
{
	t_err		err;
	char		*path;
}				t_path;

/*---- parse_error.c ---- */

void			handle_parse_error(unsigned int *parse_error, t_shell *myshell,
					int *exit_code);

/* ----- execute.c ---------- */
int				get_exit_status(int status);
int				execute_node(t_tree_node *tree, short piped, t_shell *myshell,
					int *exit_code);

/* ----- execute_builtin.c ----- */
int				execute_builtin(char **args, int *exit_code, t_shell *myshell);
int				chk_builtin(char *arg);

/* ---- execute_simple_cmd.c ----*/
int				execute_simple_cmd(t_tree_node *node, int piped,
					t_shell *myshell, int *exit_code);

/* -----  init_tree.c ----- */
void			init_tree(t_tree_node *node, t_shell *myshell, int *exit_code);

/* ------ execute_utils.c --------*/
int				is_delimiter(char *delimiter, char *str);
void			*garbage_collection(void *ptr, short clean);

/* ------ error_message.c ---------- */
int				error_message(t_err err);

/* ----- check_permission.c -------- */
t_err			check_execute(char *file, short cmd);
t_err			check_read(char *file);
t_err			check_write(char *file);

/* ------ execute_redirect.c ----- */
int				ft_out(t_io_node *io_list, int *status);
int				ft_in(t_io_node *io_list, int *status);
int				ft_append(t_io_node *io_list, int *status);

#endif