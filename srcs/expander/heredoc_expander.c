/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expander.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:41:10 by emilin            #+#    #+#             */
/*   Updated: 2024/06/03 11:41:46 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static int	heredoc_expand_writer(char *str, size_t i, int fd, int *exit_code)
{
	size_t	start;
	//char	*tmp;

	start = ++i;
	if (str[i] == '?')
		return (ft_putnbr_fd(*exit_code, fd), 2);
	while (str[i] && str[i] != '$' && str[i] != ' ')
		i++;
	if (i != start)
	{
		// tmp = ft_garbage_collector(ft_substr(str, start, i), false);
		// tmp = ft_get_envlst_val(tmp);
		// if (tmp)
		// 	ft_putstr_fd(tmp, fd);
	}
	return (i);
}

void	heredoc_expander(char *str, int fd, int *exit_code)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			i += heredoc_expand_writer(str, i, fd, exit_code);
		else
			i += (ft_putchar_fd(str[i], fd), 1);
	}
	ft_putchar_fd('\n', fd);
}
