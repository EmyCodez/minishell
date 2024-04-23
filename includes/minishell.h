/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:47:32 by esimpson          #+#    #+#             */
/*   Updated: 2024/04/22 15:23:23 by emilin           ###   ########.fr       */
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
# include "tokenizer.h"

/* --- free.c --- */
void	free_ptr(void *ptr);
void	free_exit(t_shell *myshell, int *exit_status);

# define PROMPT_MSG "\033[1;36mminishell\033[34m$ \033[0m"

/***sample test function will be changed ***/
void	test_cmd(t_shell *myshell, int *exit_status);

/* --- valid_utils.c --- */
int		is_space(char c);
int		is_empty_str(char *str);
int		is_quote(char c);
int		is_valid_input(char *buff);
#endif