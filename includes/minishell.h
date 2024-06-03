/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:47:32 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/03 13:25:04 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

/* Readline library headers */
# include <readline/history.h>
# include <readline/readline.h>

/* Libraries from includes folder */
# include "builtins.h"
# include "env.h"
# include "execution.h"
# include "parsing.h"
# include "tokenizer.h"
# include "signals.h"

# define ERR_GENERAL 2

/* --- free.c --- */
void	free_ptr(void *ptr);
void	free_2d_array(char **arr);
void	free_exit(t_shell *myshell, int *exit_status);


# define PROMPT_MSG "\033[1;36mminishell\033[34m$ \033[0m"

/***sample test function will be changed ***/
void	test_cmd(t_shell *myshell, int *exit_status);

/* --- valid_utils.c --- */
int		is_space(char c);
int		is_empty_str(char *str);
int		is_quote(char c);
int		is_valid_input(char *buff);
int     is_valid_variable_char(char ch);

/* ///////////////////////////////////////////////////EXPANDER/////////////////////////////////////////////////////////////  */

/*  ------ expander.c ------ */
char	**expand_str(char *str, int *exit_code, t_env **env_list);

/* -------- heredoc_expander ----- */
void	heredoc_expander(char *str, int fd, int *exit_code);

/* --- clean_empty_strings.c --- */
char	*clean_empty_strs(char *str);

/* ---- expand_utils.c ---- */
char * handle_dollar(char *str, size_t *i, int *exit_code, t_env **env_list);
char *handle_single_quotes(char *str, size_t *i);
char * handle_normal_str(char *str, size_t *i);
char *handle_double_quotes(char *str, size_t *i, int *exit_code, t_env **env_list);

/* ----  expander_split.c  ---------*/
char	**expander_split(char const *s);

/* ----  strip_quotes.c  ------ */
char	*strip_quotes(char *str);

#endif