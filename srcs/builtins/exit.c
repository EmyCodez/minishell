
#include "../../includes/minishell.h"
#include "../../libft/libft.h"

// void	free_tools(t_tools *tools)
// {
// 	free_arr(tools->paths);
// 	free_arr(tools->envp);
// 	free(tools->args);
// 	ft_simple_cmdsclear(&tools->simple_cmds);
// 	free(tools->pwd);
// 	free(tools->old_pwd);
// 	if (tools->pipes)
// 		free(tools->pid);
// }

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	determine_exit_code(char **argv, int *exit_code)
{
	if (argv[1] && is_str_digit(argv[1]))
		*exit_code = ft_atoi(argv[1]);
	if (argv[1] && !is_str_digit(argv[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		*exit_code = 255;
	}
	if (argv[1] && argv[2] && is_str_digit(argv[1]))
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		*exit_code = 1;
	}
	else if (!argv[1])
		*exit_code = 0;
	exit(*exit_code);
}

void	exit_cmd(char **argv, int *exit_code)
{
	ft_putendl_fd("exit", STDERR_FILENO);
	determine_exit_code(argv, exit_code);
}
