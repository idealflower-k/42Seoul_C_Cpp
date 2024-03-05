#include "minishell.h"
#include "defines.h"


t_simple_cmd_type	is_built_in_cmd(char *cmd)
{
	const char	*built_in[7] = {\
		"echo", "cd", "pwd", "export", "unset", "env", "exit"};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (ft_strncmp(cmd, built_in[i], ft_strlen(built_in[i])) == 0)
			return (i);
		i++;
	}
	return (FT_EXTERNAL);
}
