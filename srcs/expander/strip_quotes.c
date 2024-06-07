/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:19:39 by emilin            #+#    #+#             */
/*   Updated: 2024/06/07 14:12:29 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static size_t	unquoted_strlen(char *str)
{
	size_t	i;
	size_t	len;
	char	quotes;

	i = 0;
	len = 0;
	quotes = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (!quotes)
				quotes = str[i++];
			else if (str[i] == quotes)
				quotes = ((i++) && 0);
			else
				len += (i++ || 1);
		}
		else
			len += (i++ || 1);
	}
	return (len);
}

static void	unquote_filler(char *str, size_t *i, char *result, size_t *j)
{
	char	quotes;

	quotes = str[(*i)++];
	while (str[*i] != quotes)
		result[(*j)++] = str[(*i)++];
	(*i)++;
}

char	*strip_quotes(char *str)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = ft_calloc(1 + unquoted_strlen(str), sizeof(char));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			(unquote_filler(str, &i, result, &j));
		else
			result[j++] = str[i++];
	}
	return (free_ptr(str), result);
}
