/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:22:59 by emilin            #+#    #+#             */
/*   Updated: 2024/06/09 13:00:36 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static char	*pre_expander(char *str, int *exit_code, t_env **env_list)
{
	char	*result;
	size_t	i;

	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			result = ft_strjoin_free(result, handle_single_quotes(str, &i));
		else if (str[i] == '"')
			result = ft_strjoin_free(result, handle_double_quotes(str, &i, exit_code,env_list));
		else if (str[i] == '$')
			result = ft_strjoin_free(result, handle_dollar(str, &i, exit_code, env_list ));
		else
			result = ft_strjoin_free(result, handle_normal_str(str, &i));
	}
	return (result);
}

char	**expand_str(char *str, int *exit_code, t_env **env_list)
{
	char	**expanded;
	size_t	i;

	str = pre_expander(str, exit_code, env_list);
	if (!str)
		return (NULL);
	str = clean_empty_strs(str);
	if (!str)
		return (NULL);
	expanded = expander_split(str);
	free(str);
	if (!expanded)
		return (NULL);
	i = 0;
	while (expanded[i])
	{
		expanded[i] = strip_quotes(expanded[i]);
		i++;
	}
	return (expanded);
}
