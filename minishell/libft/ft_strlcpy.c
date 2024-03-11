/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:24:24 by esimpson          #+#    #+#             */
/*   Updated: 2023/07/12 15:03:30 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = dstsize - 1;
	i = 0;
	while (src[i] != '\0' && i < len && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	size_t n;
// 	//char *src = "lorem ipsum dolor sit amet";
// 	char dest[75] ;
// 	n = 3;
// 	printf("%lu", ft_strlcpy(dest, "lorem ipsum", 3));
// 	printf("\n %s", dest);
// 	return (0);
// }