/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:14:26 by esimpson          #+#    #+#             */
/*   Updated: 2023/10/18 13:34:49 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_read_stash(int fd, char *stash)
{
	char	*tmp_str;
	int		bytes_read;

	tmp_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (!tmp_str)
		return (free(stash), NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, tmp_str, BUFFER_SIZE - 1);
		if (bytes_read == -1)
		{
			free(stash);
			free(tmp_str);
			return (NULL);
		}
		tmp_str[bytes_read] = '\0';
		stash = ft_gnljoin(stash, tmp_str);
		if (!stash || !*stash)
			return (free(stash), free(tmp_str), NULL);
	}
	free(tmp_str);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
	{
		return (0);
	}
	stash = ft_read_stash(fd, stash);
	if (!stash || !*stash)
		return (free(stash), NULL);
	line = ft_getline(stash);
	if (!line || !*line)
		return (free(stash), free(line), NULL);
	stash = ft_update_stash(stash);
	return (line);
}
