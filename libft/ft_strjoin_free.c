/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:42:59 by emilin            #+#    #+#             */
/*   Updated: 2024/05/27 13:48:19 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin_free(char *s1, char *s2)
{
    size_t	i;
	size_t	j;
    size_t total_len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1)+1 + ft_strlen(s2)+1;
	join = (char *)malloc(sizeof(char) * (total_len));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = 0;
	return (free(s1),free(s2),join);
}