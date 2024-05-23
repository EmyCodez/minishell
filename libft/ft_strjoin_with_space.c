/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_with_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:01:50 by emilin            #+#    #+#             */
/*   Updated: 2024/05/20 11:26:36 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_with_space(char const *s1, char const *s2, char c)
{
	size_t	i;
	size_t	j;
    size_t total_len;
	char	*join;

	if (!s1 || !s2)
		return (ft_strdup(""));
	if (!c || !ft_strlen(s1) || !ft_strlen(s2))
		return (ft_strjoin(s1,s2));
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
	join[i++] = c;
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = 0;
	return (join);
}