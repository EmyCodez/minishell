/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:38:55 by esimpson          #+#    #+#             */
/*   Updated: 2023/10/17 12:58:47 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnljoin(char *stash, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!stash)
	{
		stash = (char *)malloc(sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !s2)
		return (NULL);
	join = malloc(sizeof(char) * ((ft_strlen(stash) + ft_strlen(s2) + 1)));
	if (!join)
		return (free(stash), free(s2), NULL);
	i = -1;
	while (stash[++i])
		join[i] = stash[i];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(stash);
	return (join);
}

char	*ft_getline(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !stash[i])
		return (free(stash), NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_stash(char *stash)
{
	int		len;
	int		i;
	char	*new_str;

	len = 0;
	i = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (!stash[len])
	{
		free(stash);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * ((ft_strlen(stash) - len + 1)));
	if (!new_str)
		return (NULL);
	len++;
	if (!stash[len])
		return (free(stash), free(new_str), NULL);
	while (stash[len])
		new_str[i++] = stash[len++];
	new_str[i] = '\0';
	free(stash);
	return (new_str);
}
