#include "minishell.h"
#include "defines.h"
#include "meta_command.h"
#include "envp_command.h"

void	set_err_num(int arg)
{
	meta_receiver(SET_ERR_NUM, arg, NULL);
}

void	set_exit_status(int arg)
{
	meta_receiver(SET_EXIT_STATUS, arg, NULL);
}

char	*get_cur_dir(void)
{
	return (meta_receiver(GET_CUR_DIR, 0, NULL));
}

void	set_cur_dir(char *str)
{
	meta_receiver(SET_CUR_DIR, 0, str);
}
