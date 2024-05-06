/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:54:15 by emilin            #+#    #+#             */
/*   Updated: 2024/05/06 15:24:31 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "tokenizer.h"

/* Parsing syntax and memory errors */
# define ERR_MEMORY 1
# define ERR_SYNTAX 2

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

/* --- parsing.c ---- */
t_tree_node				*parser(t_token *token_list, int *exit_code);

/* --- parsing_utils.c --- */
int						is_binary_operator(t_token *curr_token);
int						is_redirect(t_token_type tkn_type);
t_tree_node				*get_simple_cmd(t_token *curr_token, int *parse_error);

/* --- parser_nodes.c --- */
t_tree_node				*new_node(t_node_type type);

/* --- parse_error.c --- */
void					set_parse_error(unsigned int *parse_error,
							int error_type);

/* --- parser_clear.c --- */
void					clear_cmd_node(t_tree_node *node);

#endif