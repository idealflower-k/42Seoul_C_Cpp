#include "minishell.h"
#include "defines.h"
#include "signal_controller.h"

void	signal_controller(t_signal_flags flag, pid_t pid)
{
	struct sigaction	s_int;
	struct sigaction	s_quit;

	if (flag == SIG_INIT)
		signal_init(&s_int, &s_quit);
	else if (flag == SIG_CHILD)
		signal_child(pid);
	else if (flag == SIG_HERE)
		signal_heredoc(pid);
}
