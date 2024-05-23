/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:54:15 by emilin            #+#    #+#             */
/*   Updated: 2024/05/21 07:21:52 by emilin           ###   ########.fr       */
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
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}						t_tree_node;

/* --- parser.c ---- */
t_tree_node	*parser(t_token **token_list,  t_token **current_token, unsigned int	*parse_error);
t_tree_node	*find_expression(t_token **current_token, unsigned int *parse_error,
		t_token **token_list);

/* --- parsing_utils.c --- */
int						is_binary_operator(t_token *curr_token);
int						is_redirect(t_token_type tkn_type);
t_tree_node	*get_simple_cmd(t_token **curr_token, unsigned int *parse_error);
int	get_io_list(t_io_node **io_list, unsigned int *parse_error,
		t_token **current_token);

/* --- parser_nodes.c --- */
t_tree_node				*new_node(t_node_type type);
t_io_type	get_io_type(t_token_type type);
t_node_type	get_node_type(t_token_type tkn_type);
t_io_node	*new_io_node(t_token_type type, char *value);
void	append_io_node(t_io_node **lst, t_io_node *new);


/* --- parse_error.c --- */
void					set_parse_error(unsigned int *parse_error,
							int error_type);

/* --- parser_clear.c --- */
void	clear_io_list(t_io_node **io_list);
void	clear_cmd_node(t_tree_node *node);
void	clear_tree(t_tree_node **tree, t_token **token_list);

#endif