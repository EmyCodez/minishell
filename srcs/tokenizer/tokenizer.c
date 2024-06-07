/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:52:36 by emilin            #+#    #+#             */
/*   Updated: 2024/06/07 15:41:10 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	handle_separator(char **input, t_token **token_list)
{
	if (!ft_strncmp(*input, "<<", 2))
		return (append_separator(TK_DB_LESS, input, token_list) && 1);
	else if (!ft_strncmp(*input, ">>", 2))
		return (append_separator(TK_DB_GREATER, input, token_list) && 1);
	else if (!ft_strncmp(*input, "<", 1))
		return (append_separator(TK_LESS, input, token_list) && 1);
	else if (!ft_strncmp(*input, ">", 1))
		return (append_separator(TK_GREATER, input, token_list) && 1);
	else if (!ft_strncmp(*input, "(", 1))
		return (append_separator(TK_OPEN_PAR, input, token_list) && 1);
	else if (!ft_strncmp(*input, ")", 1))
		return (append_separator(TK_CLOSE_PAR, input, token_list) && 1);
	else
		return (append_separator(TK_PIPE, input, token_list) && 1);
}

static t_token	*token_handler(char *input, int *exit_code)
{
	t_token	*token_list;
	int		error;

	token_list = NULL;
	error = 0;
	while (*input)
	{
		if (error)
		{
			free_token_list(&token_list);
			return (NULL);
		}
		if (is_space(*input))
			skip_spaces(&input);
		else if (chk_spl_chars(*input))
			error = (!handle_separator(&input, &token_list) && 1);
		else
			error = (!append_identifier(&token_list, &input, exit_code) && 1);
	}
	return (token_list);
}

// static void	print_token_list(t_token *token_list)
// {
// 	printf("\n List of tokens \n");
// 	while (token_list)
// 	{
// 		if (token_list->tk_value)
// 			printf(" %s ", token_list->tk_value);
// 		else
// 			printf(" %d ", token_list->tk_type);
// 		token_list = token_list->next;
// 	}
// }

t_token	*tokenizer(char *input, int *exit_code)
{
	t_token	*token_list;

	token_list = token_handler(input, exit_code);
	return (token_list);
}
