/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:10:04 by esimpson          #+#    #+#             */
/*   Updated: 2024/03/23 12:14:17 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isascii(int c)
{
	if ((unsigned int)c > 0 && (unsigned int)c <= 127)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= 47)
// 	{
// 		printf(" %d", (ft_isascii(i)));
// 		i++;
// 	}
// 	return (0);
// }
