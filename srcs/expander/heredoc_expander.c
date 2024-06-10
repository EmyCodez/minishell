/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expander.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:41:10 by emilin            #+#    #+#             */
/*   Updated: 2024/06/10 13:36:36 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static int	heredoc_expand_writer(char *str, size_t i, int fd, t_shell *myshell)
{
	size_t	start;
	char	*tmp;

	start = ++i;
	if (str[i] == '?')
		return (ft_putnbr_fd(myshell->exit_code, fd), 2);
	while (str[i] && str[i] != '$' && str[i] != ' ')
		i++;
	if (i != start)
	{
		tmp = garbage_collection(ft_substr(str, start, i), 0);
		tmp = get_env_value(myshell->env_list, tmp);
		if (tmp)
			ft_putstr_fd(tmp, fd);
	}
	return (i);
}

void	heredoc_expander(char *str, int fd, t_shell *myshell)
{
	size_t	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			i += heredoc_expand_writer(str, i, fd, myshell);
		else
			i += (ft_putchar_fd(str[i], fd), 1);
	}
	ft_putchar_fd('\n', fd);
}
