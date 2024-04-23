/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:17:48 by emilin            #+#    #+#             */
/*   Updated: 2024/04/23 12:13:41 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

void	skip_spaces(char **str)
{
	while (**str && is_space(**str))
		(*str)++;
}

int	chk_spl_chars(char ch)
{
	char	*str_spl;

	str_spl = "<>|()";
	while (*str_spl)
	{
		if (ch == *str_spl)
			return (1);
		str_spl++;
	}
	return (0);
}

int	is_separator(char *str)
{
	if (*str == 32 || *str == '\t' || chk_spl_chars(*str))
		return (1);
	return (0);
}

int	skip_quotes(char *input, int *pos)
{
	char	quote;

	quote = input[*pos];
	if (ft_strchr(input + *pos + 1, quote))
	{
		(*pos)++;
		while (input[*pos] != quote)
			(*pos)++;
		(*pos)++;
		return (1);
	}
	return (0);
}

void	print_quote_error(char c, int *exit_code)
{
	ft_putstr_fd("minishell: unexpected EOF while looking for matching `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
	*exit_code = 258;
}
