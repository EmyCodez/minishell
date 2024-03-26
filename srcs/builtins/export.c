/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:21:40 by emilin            #+#    #+#             */
/*   Updated: 2024/03/26 13:54:02 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static void	print_env(t_env *env_list)
{
	t_env	*temp;

	temp = env_list;
	while (temp)
	{
		if (temp->value)
			printf("declare -x %s=%s\n", temp->key, temp->value);
		else
			printf("declare -x %s\n", temp->key);
		temp = temp->next;
	}
}

void	insert_export_var(char *key, t_env **env_list, char *equal_loc)
{
	t_env	*new_node;

	if (!equal_loc)
		new_node = new_env_node(key, NULL);
	else
		new_node = new_env_node(key, ft_strdup(equal_loc + 1));
	env_sort_insert(env_list, new_node);
}

char	*extract_key(char *str, char *equal_loc)
{
	char	*key;

	if (!equal_loc)
		key = ft_strdup(str);
	else
		key = ft_substr(str, 0, equal_loc - str);
	return (key);
}

int	is_valid_key(char *key)
{
	int	i;

	i = 0;
	if (!ft_isalpha(key[i]) && key[i] != '_')
		return (0);
	while (key[++i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
	}
	return (1);
}

void	export(char **args, t_env **env_list, int *exit_status)
{
	int		i;
	char	*key;
	char	*equal_loc;

	if (!args[1])
	{
		print_env(*env_list);
		return ;
	}
	i = 0;
	while (args[++i])
	{
		equal_loc = ft_strchr(args[i], '=');
		key = extract_key(args[i], equal_loc);
		if (!is_valid_key(key))
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("' : not a valid identifier\n", 2);
			*exit_status = 1;
			free(key);
		}
		else
			insert_export_var(key, env_list, equal_loc);
	}
}
