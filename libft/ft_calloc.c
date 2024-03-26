/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:15:04 by esimpson          #+#    #+#             */
/*   Updated: 2024/03/23 12:16:04 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > (UINT32_MAX / size))
		return (NULL);
	ptr = (void *)malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

// int	main(void)
// {
// 	size_t	n;
// 	size_t	i;
// 	int		*num;

// 	n = 5;
// 	i = 0;
// 	num = (int *)ft_calloc(n, sizeof(int));
// 	while (i < n)
// 		printf("num=%d ", num[i++]);
// 	return (0);
// }
