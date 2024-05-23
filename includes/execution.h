/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:09:46 by emilin            #+#    #+#             */
/*   Updated: 2024/05/20 15:50:53 by emilin           ###   ########.fr       */
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
}				t_shell;

/*---parse_error.c ----*/

void	handle_parse_error(unsigned int *parse_error,
		t_shell *myshell, int *exit_code);

#endif