#include "minishell.h"
#include "defines.h"
#include "envp_command.h"
#include "meta_command.h"

void	set_envp_elem(const char *key, const char *val)
{
	envp_receiver(SET, key, val, NULL);
}

t_hash_elem	*get_envp_elem(const char *key)
{
	return (envp_receiver(GET, key, NULL, NULL));
}

void	del_envp_elem(const char *key)
{
	envp_receiver(DEL, key, NULL, NULL);
}

void	print_envp_elem(const char *option)
{
	envp_receiver(PRINT, NULL, NULL, option);
}

char	**convert_char_arr(void)
{
	return (hash_convert_arr(get_envp()));
}
