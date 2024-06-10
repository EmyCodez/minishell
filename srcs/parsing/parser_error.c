/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:10:06 by emilin            #+#    #+#             */
/*   Updated: 2024/06/10 13:00:45 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

void	set_parse_error(unsigned int *parse_error, int error_type)
{
	*parse_error = error_type;
}

void	handle_parse_error(unsigned int *parse_error,
		t_shell *myshell)
{
	char			**tkn_values;
	t_token_type	token_type;

	tkn_values = (char *[]){"TK_IDENTIFIER", "<", ">", "<<", ">>", "|", "(",
		")", "newline"};
	if (*parse_error)
	{
		if (*parse_error == ERR_SYNTAX)
		{
			if (!myshell->curr_token)
				token_type = TK_NEW_LINE;
			else
				token_type = myshell->curr_token->tk_type;
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			ft_putstr_fd(tkn_values[token_type], 2);
			ft_putstr_fd("'\n", 2);
			myshell->exit_code = 258;
		}
		clear_tree(&myshell->tree, &myshell->token_lst);
		*parse_error = 0;
	}
}
