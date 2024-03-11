/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:02:38 by esimpson          #+#    #+#             */
/*   Updated: 2024/03/11 11:40:07 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

void	free_array(char **str_array, int index)
{
	int	i;

	i = 0;
	while (i <= index && str_array[i])
		free(str_array[i++]);
	free(str_array);
}

char	**arr_2d_dup(char **arr)
{
	char	**dup;
	int		len;

	if (!arr)
		return (NULL);
	len = 0;
	while (arr[len])
		len++;
	dup = malloc(sizeof(char *) * (len + 1));
	if (!dup)
		return (NULL);
	len = 0;
	while (arr[len])
	{
		dup[len] = ft_strdup(arr[len]);
		if (!dup[len])
		{
			free_array(arr, len);
			return (NULL);
		}
		len++;
	}
	dup[len] = NULL;
	return (dup);
}
