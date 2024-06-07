/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_empty_strings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:26:06 by emilin            #+#    #+#             */
/*   Updated: 2024/06/07 14:04:54 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"


char	*clean_empty_strs(char *str)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	*result;
	size_t	dstsize;

	if ((str[0] == '\'' && str[1] == '\'' && !str[2])
		|| (str[0] == '"' && str[1] == '"' && !str[2]))
		return (str);
	tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '\'' && str[i + 1] == '\'')
			|| (str[i] == '"' && str[i + 1] == '"'))
			i += 2;
		else
			tmp[j++] = str[i++];
	}
	free(str);
	dstsize = ft_strlen(tmp) + 1;
	result = ft_calloc(dstsize, sizeof(char));
	return (ft_strlcpy(result, tmp, dstsize), free_ptr(tmp), result);
}
