/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expander.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:41:10 by emilin            #+#    #+#             */
/*   Updated: 2024/06/09 12:39:59 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static int	heredoc_expand_writer(char *str, size_t i, int fd, int *exit_code)
{
	if (str[i] == '?')
		return (ft_putnbr_fd(*exit_code, fd), 2);
	while (str[i] && str[i] != '$' && str[i] != ' ')
		i++;
	return (i);
}

void	heredoc_expander(char *str, int fd, t_shell *myshell, int *exit_status)
{
	size_t	i;
	size_t	start;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			start = ++i;
			i += heredoc_expand_writer(str, i, fd, exit_status);
			if (i != start)
			{
				tmp = garbage_collection(ft_substr(str, start, i), 0);
				tmp = get_env_value(myshell->env_list, tmp);
				if (tmp)
					ft_putstr_fd(tmp, fd);
			}
		}
		else
			i += (ft_putchar_fd(str[i], fd), 1);
	}
	ft_putchar_fd('\n', fd);
}
