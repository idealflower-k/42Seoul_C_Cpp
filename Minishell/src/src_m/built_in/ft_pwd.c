#include "minishell.h"
#include "defines.h"
#include <errno.h>
#include "meta_command.h"
#include "error.h"

int	ft_pwd(t_simple_cmd *simple_cmd)
{
	static char	*prev_cwd;
	char		*cwd;

	(void)simple_cmd;
	cwd = get_cur_dir();
	if (cwd)
	{
		ft_putstr_fd(cwd, STDOUT_FILENO);
		if (prev_cwd)
			free(prev_cwd);
		prev_cwd = ft_strdup(cwd);
	}
	else
		ft_putstr_fd(prev_cwd, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
