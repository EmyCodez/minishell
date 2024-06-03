/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:43:43 by emilin            #+#    #+#             */
/*   Updated: 2024/06/03 11:49:42 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_empty_str(char *str)
{
	while (*str)
	{
		if (!is_space(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

int	is_valid_input(char *buff)
{
	if (ft_strlen(buff) == 0 || is_empty_str(buff))
		return (0);
	return (1);
}

int is_valid_variable_char(char ch)
{
	if(ft_isalnum(ch) || ch == '_')
		return(1);
	return(0);	
}