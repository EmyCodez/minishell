/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:12:57 by emilin            #+#    #+#             */
/*   Updated: 2024/05/29 13:45:00 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

char * handle_dollar(char *str, size_t *i, int *exit_code, t_env **env_list)
{
	size_t start;
    char *var;
    char *env_val;

    (*i)++;
    if(ft_isdigit(str[*i]) || str[*i] == '@' )
    {
        (*i)++;
        return(ft_strdup(""));
    }
    else if (str[*i] == '?')
    {
        (*i)++;
        return(ft_itoa(*exit_code));
    }
    else if(!is_valid_variable_char(str[*i]))
        return(ft_strdup("$"));
    start =*i;
    while( is_valid_variable_char(str[*i]))
        (*i)++;
    var = ft_substr(str, start, *i - start);
    env_val =  get_env_value(*env_list, var);
    if(!env_val)
        return(free_ptr(var),ft_strdup(""));
    return( free_ptr(var), ft_strdup(env_val));    
}

char *handle_single_quotes(char *str, size_t *i)
{
    size_t start;

    start = *i;
    (*i)++;
    while(str[*i]!= '\'')
        (*i)++;
    (*i)++;
    return(ft_substr(str,start, *i - start));    
}

char * handle_normal_str(char *str, size_t *i)
{
    size_t start;

    start=*i;
    while(str[*i] &&  str[*i] != '\'' && str[*i] != '"' && str[*i] != '$')
        (*i)++;
    return(ft_substr(str,start, *i - start));
}

static char *handle_double_quote_str(char *str, size_t *i)
{
    size_t start;

    start=*i;
    while(str[*i] && str[*i] != '"' && str[*i] != '$')
        (*i)++;
    return(ft_substr(str,start, *i - start));
}

char *handle_double_quotes(char *str, size_t *i, int *exit_code, t_env **env_list)
{
   char *result;

   result = ft_strdup("\"");
   (*i)++;
   while(str[*i] != '"')
   {
        if(str[*i] == '$')
            result = ft_strjoin_free(result, handle_dollar(str,i,exit_code, env_list));
        else
            result = ft_strjoin_free(result,handle_double_quote_str(str,i));
   }
   (*i)++;
   return(ft_strjoin_free(result, ft_strdup("\"")));  
}
