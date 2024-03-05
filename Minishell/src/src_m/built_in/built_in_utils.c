#include "minishell.h"

t_bool	is_valid_params(char c)
{
	if (c == '_')
		return (FT_TRUE);
	if (ft_isspecial(c) || c == '\0')
		return (FT_FALSE);
	return (FT_TRUE);
}
