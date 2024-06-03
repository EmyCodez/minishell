/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:33:24 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/03 15:09:29 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

static void	init_shell(t_shell *myshell, char **envp, int *exit_code)
{
	*exit_code = 0;
	myshell->env = envp;
	myshell->token_lst = 0;
	init_env_list(envp, &myshell->env_list);
	myshell->curr_token = 0;
	myshell->tree = 0;
	myshell->heredoc_sigint = 0;
	myshell->sigint_child = 0;
}

static void start_execution(t_shell *myshell, int *exit_code)
{
	init_tree(myshell->tree, myshell, exit_code);
	if(myshell->heredoc_sigint)
	{
		clear_tree(&myshell->tree, &myshell->token_lst);
		myshell->heredoc_sigint = 0;
		*exit_code = execute_node(myshell->tree,0,myshell,exit_code);
	}
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

static void	command_execution(t_shell *myshell, int *exit_code)
{
	unsigned int parse_error;
	
	parse_error=0;
	add_history(myshell->buff);
	myshell->token_lst = tokenizer(myshell->buff, exit_code);
	myshell->curr_token=myshell->token_lst;
	myshell->tree = parser(&myshell->token_lst,&myshell->curr_token, &parse_error);
	if(parse_error)
		handle_parse_error(&parse_error,myshell, exit_code);
			
	printf("\n Tree Nodes \n");
	//inorderTraversal(myshell->tree);		
	start_execution(myshell,exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	myshell;
	int		exit_code;

	(void)argc;
	(void)argv;
	exit_code = 0;
	init_shell(&myshell, envp, &exit_code);
	while (1)
	{
		myshell.buff = readline(PROMPT_MSG);
		if (!myshell.buff)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			free_env_list(myshell.env_list);
			return (exit_code);
		}
		if (!is_valid_input(myshell.buff))
			free_ptr(myshell.buff);
		else
			command_execution(&myshell, &exit_code);
	}
	rl_clear_history();
	free_env_list(myshell.env_list);
	free_token_list(&myshell.token_lst);
	return (exit_code);
}
