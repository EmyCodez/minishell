/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:21:39 by emilin            #+#    #+#             */
/*   Updated: 2024/06/03 15:05:57 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int execute_node(t_tree_node *tree, short piped, t_shell *myshell, int *exit_code)
{
    //int status;

    if(!tree)
        return(1);
    execute_simple_cmd(tree, piped,myshell,exit_code);
    return(0);
}
