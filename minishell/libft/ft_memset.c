/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:28:22 by esimpson          #+#    #+#             */
/*   Updated: 2023/07/26 12:18:59 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	ch;

	ptr = b;
	ch = (unsigned char)c;
	while (len-- > 0)
		*ptr++ = ch;
	return (b);
}

// int	main(void)
// {
// 	char src[10];
// 	int n = sizeof(src) / sizeof(src[0]);

// 	int i;
// 	i = 0;
// 	ft_memset(src, 'a', sizeof(src));
// 	printf("\nCopied %d characters  \n",n );

// 	while (i < n)
// 	{
// 		printf("%c ", src[i]);
// 		i++;
// 	}

// 	return (0);
// }