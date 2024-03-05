#include "minishell.h"
#include "defines.h"
#include "parser.h"
#include "utils.h"
#include "expander.h"
#include "signal_controller.h"
#include "executor.h"
#include "meta_command.h"
#include "data_structure.h"
#include "error.h"

void	prompt(t_meta *meta, t_tree *tree)
{
	char	*line;

	while (FT_TRUE)
	{
		signal_controller(SIG_INIT, 0);
		meta->cur_dir = redef_cur_dir(meta->cur_dir);
		meta->prompt = make_prompt(meta->prompt);
		line = readline(meta->prompt);
		if (!line)
		{
			printf("exit\n");
			clear_history();
			exit(EXIT_SUCCESS);
		}
		add_history(line);
		parser(line, tree);
		if (meta->err == ERR_NOTHING)
		{
			expander(tree->root);
			executor(tree);
		}
		err_handler(meta);
		clear_asset(line, tree, meta);
	}
}
