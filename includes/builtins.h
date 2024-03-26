#ifndef BUILTINS_H
# define BUILTINS_H

/* Library files */
# include "../includes/env.h"

typedef struct s_shell
{
	char	*buff;
	char	**env;
	t_env	*env_list;
	// t_list				**var;
	// t_cmd				*cmds;
}			t_shell;

void		pwd(int *exit_status);
void		env(t_shell *myshell);
void		echo(char **av);
void		exit_cmd(t_shell *myshell, int *exit_status);
void		export(char **args, t_env **env_list, int *exit_status);
#endif
