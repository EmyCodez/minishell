/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:35:15 by esimpson          #+#    #+#             */
/*   Updated: 2023/07/26 15:41:18 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	node_cnt;

	if (!lst)
		return (0);
	node_cnt = 0;
	while (lst)
	{
		lst = lst->next;
		node_cnt++;
	}
	return (node_cnt);
}
