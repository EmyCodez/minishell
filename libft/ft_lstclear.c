/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:59:24 by esimpson          #+#    #+#             */
/*   Updated: 2023/07/26 14:57:00 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	if (!del || !lst)
		return ;
	head = *lst;
	while (head != NULL)
	{
		temp = head->next;
		(*del)(head->content);
		free(head);
		head = temp;
	}
	*lst = NULL;
}
