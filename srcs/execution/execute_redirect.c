/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:51:09 by emilin            #+#    #+#             */
/*   Updated: 2024/06/10 11:02:16 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_out(t_io_node *io_list, int *status)
{
	int	fd;

	if (!io_list->exp_value || io_list->exp_value[1])
	{
		*status = error_message((t_err){ENO_GENERAL, ERRMSG_AMBIGUOUS,
				io_list->value});
		return (*status);
	}
	fd = open(io_list->exp_value[0], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		*status = error_message(check_write(io_list->exp_value[0]));
		return (*status);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	*status = 0;
	return (*status);
}

int	ft_in(t_io_node *io_list, int *status)
{
	int	fd;

	if (!io_list->exp_value || io_list->exp_value[1])
	{
		*status = error_message((t_err){ENO_GENERAL, ERRMSG_AMBIGUOUS,
				io_list->value});
		return (*status);
	}
	fd = open(io_list->exp_value[0], O_RDONLY);
	if (fd == -1)
	{
		*status = error_message(check_read(io_list->exp_value[0]));
		return (*status);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	*status = 0;
	return (*status);
}

int	ft_append(t_io_node *io_list, int *status)
{
	int	fd;

	if (!io_list->exp_value || io_list->exp_value[1])
	{
		*status = error_message((t_err){ENO_GENERAL, ERRMSG_AMBIGUOUS,
				io_list->value});
		return (*status);
	}
	fd = open(io_list->exp_value[0], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		*status = error_message(check_write(io_list->exp_value[0]));
		return (*status);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	*status = 0;
	return (0);
}
