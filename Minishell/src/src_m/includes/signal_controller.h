#ifndef SIGNAL_CONTROLLER_H
# define SIGNAL_CONTROLLER_H


void	set_signal_init(int signum);
void	signal_init(struct sigaction *s_int, struct sigaction *s_quit);


void	signal_child(pid_t	pid);


void	signal_heredoc(pid_t	pid);


void	signal_controller(t_signal_flags flag, pid_t pid);

#endif