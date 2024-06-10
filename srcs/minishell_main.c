/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:33:24 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/10 15:56:29 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

static void	init_shell(t_shell *myshell, char **envp)
{
	ft_memset(myshell, 0, sizeof(t_shell));
	myshell->env = envp;
	myshell->env_list = 0;
	myshell->token_lst = 0;
	init_env_list(envp, &myshell->env_list);
	myshell->curr_token = 0;
	myshell->heredoc_sigint = 0;
	myshell->sigint_child = 0;
}

static void	start_execution(t_shell *myshell)
{
	init_tree(myshell->tree, myshell);
	if (myshell->heredoc_sigint)
	{
		clear_tree(&myshell->tree, &myshell->token_lst);
		myshell->heredoc_sigint = 0;
	}
	myshell->exit_code = execute_node(myshell->tree, 0, myshell);
	clear_tree(&myshell->tree, &myshell->token_lst);
}

// static void inorderTraversal(t_tree_node* root) {
//     if (root != NULL) {
// 		if(root->left)
//           inorderTraversal(root->left); // Traverse left subtree
//         printf("node type = %d \n", root->type);
// 		if(root->args)
// 		printf("arg_list = %s \n",root->args);
// 		if(root->right)    // Print the data of the current node
//         inorderTraversal(root->right); // Traverse right subtree
//     }
// }

static void	command_execution(t_shell *myshell)
{
	unsigned int	parse_error;

	parse_error = 0;
	add_history(myshell->buff);
	myshell->token_lst = tokenizer(myshell->buff, &myshell->exit_code);
	myshell->curr_token = myshell->token_lst;
	myshell->tree = parser(&myshell->token_lst, &myshell->curr_token,
			&parse_error);
	if (parse_error)
		handle_parse_error(&parse_error, myshell);
	start_execution(myshell);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	myshell;
	
	(void)argc;
	(void)argv;
	
	init_shell(&myshell, envp);
	while (1)
	{
		myshell.buff = readline(PROMPT_MSG);
		if (!myshell.buff)
		{
			ft_putstr_fd("exit\n", 1);
			clean_shell(&myshell);
			return (myshell.exit_code);
		}
		if (!is_valid_input(myshell.buff))
			free_ptr(myshell.buff);
		else
			command_execution(&myshell);
	}
	garbage_collection(NULL, 1);
	return (clean_shell(&myshell), myshell.exit_code);
}
