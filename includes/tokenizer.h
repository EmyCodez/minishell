/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:53:27 by emilin            #+#    #+#             */
/*   Updated: 2024/04/27 15:50:08 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

typedef enum e_token_type
{
	TK_IDENTIFIER,
	TK_LESS,
	TK_GREATER,
	TK_DB_LESS,
	TK_DB_GREATER,
	TK_PIPE,
	TK_OPEN_PAR,
	TK_CLOSE_PAR,
	TK_NL,
}					t_token_type;

typedef struct s_token
{
	t_token_type	tk_type;
	char			*tk_value;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

/* --- tokenizer.c --- */
t_token				*tokenizer(char *input, int *exit_code);

/* --- token_append.c --- */
int					append_separator(t_token_type tok_type, char **input,
						t_token **token_lst);
int					append_identifier(t_token **token_lst, char **input,
						int *exit_code);

/* --- token_list.c --- */
t_token				*new_token_node(char *value, t_token_type type);
void				add_to_token_list(t_token **token_lst, t_token *new_token);
void				free_token_list(t_token **token_lst);

/* --- token_utils.c ---- */
void				skip_spaces(char **str);
int					chk_spl_chars(char ch);
int					is_separator(char *str);
int					skip_quotes(char *input, int *pos);
void				print_quote_error(char c, int *exit_code);

#endif
