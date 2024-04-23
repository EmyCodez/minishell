/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:26:28 by emilin            #+#    #+#             */
/*   Updated: 2024/04/23 12:57:06 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	append_separator(t_token_type tok_type, char **input, t_token **token_lst)
{
	t_token	*token;

	token = new_token_node(NULL, tok_type);
	if (!token)
		return (0);
	add_to_token_list(token_lst, token);
	(*input)++;
	if (tok_type == TK_DB_LESS || tok_type == TK_DB_GREATER)
		(*input)++;
	return (1);
}

int	append_identifier(t_token **token_lst, char **input, int *exit_code)
{
	char	*str_temp;
	char	*value;
	t_token	*token;
	int		pos;

	str_temp = *input;
	pos = 0;
	while (str_temp[pos] && !is_separator(&str_temp[pos]))
	{
		{
			if (is_quote(str_temp[pos]) && (!skip_quotes(str_temp, &pos)))
				print_quote_error(str_temp[pos], exit_code);
			else
				pos++;
		}
	}
	value = ft_substr(str_temp, 0, pos);
	if (!value)
		return (0);
	token = new_token_node(value, TK_IDENTIFIER);
	if (!token)
		return (free_ptr(value), 0);
	*input += pos;
	add_to_token_list(token_lst, token);
	return (1);
}
