/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:29:09 by emilin            #+#    #+#             */
/*   Updated: 2024/05/30 16:26:49 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void init_leaf(t_tree_node *node, t_shell *myshell, int *exit_code)
{
    t_io_node *io;

    if(node->args)
    node->exp_args = expand_str(node->args,exit_code,&myshell->env_list);
    io = node->io_list;
}

void init_tree(t_tree_node *node, t_shell *myshell, int *exit_code)
{
    if(!node)
        return;
    if(node->type == ND_PIPE)
    {
        init_tree(node->left,myshell,exit_code);
        if(!myshell->heredoc_sigint)
            init_tree(node->right,myshell,exit_code);
    }
    else
        init_leaf(node, myshell);

}
void initialize_tree(t_shell *myshell, int *exit_code)
{
    

}