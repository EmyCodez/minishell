/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:54:15 by emilin            #+#    #+#             */
/*   Updated: 2024/04/27 16:03:45 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "tokenizer.h"

typedef enum e_node_type
{
	ND_PIPE,
	ND_CMD
}						t_node_type;

typedef enum e_io_type
{
	IO_IN,
	IO_OUT,
	IO_HEREDOC,
	IO_APPEND
}						t_io_type;

typedef struct s_io_node
{
	t_io_type			type;
	int					heredoc;
	char				*value;
	char				**exp_value;
	struct s_io_node	*prev;
	struct s_io_node	*next;
}						t_io_node;

typedef struct s_tree_node
{
	t_node_type			type;
	char				*args;
	char				**exp_args;
	t_io_node			*io_list;
	struct s_tree_node	*prev;
	struct s_tree_node	*next;
}						t_tree_node;

/* --- parsing.h ---- */
t_tree_node				*parser(t_token *token_list, int *exit_code);

#endif
