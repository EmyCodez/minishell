#include "../../includes/minishell.h"
#include "../../libft/libft.h"

void	exit_cmd(t_shell *myshell, int *exit_status)
{
	free_exit(myshell, exit_status);
}
