#include "pipex_bonus.h"

int	main(int ac, char *av[], char *envp[])
{
	t_cmd	**cmd_arr;
	t_args	*arg_info;

	if (ac < 5)
		ft_error("argument not enough : least 5 need");
	arg_info = set_arg_info(ac, av, envp);
	cmd_arr = open_and_pars(arg_info);
	fork_exec(arg_info, cmd_arr, 0, arg_info->io_fd[0]);
	exit(WEXITSTATUS(arg_info->status_child));
}

t_cmd	**open_and_pars(t_args *arg_info)
{
	t_cmd	**result;

	if (ft_strncmp(arg_info->av[1], "here_doc", ft_strlen(arg_info->av[1])) \
		== 0)
	{
		make_temp_file(arg_info);
		out_file_open(arg_info);
		arg_info->total_cmd = arg_info->ac - 4;
		return (parsing_av(arg_info->ac - 4, arg_info->av + 3, \
			arg_info->envp, arg_info));
	}
	else
	{
		arg_info->io_fd[0] = open(arg_info->av[1], O_RDONLY);
		if (arg_info->io_fd[0] == -1)
			perror("infile open() error");
		out_file_open(arg_info);
		arg_info->total_cmd = arg_info->ac - 3;
		result = parsing_av(arg_info->ac - 3, arg_info->av + 2, \
			arg_info->envp, arg_info);
		return (result);
	}
}

void	fork_exec(t_args *args, t_cmd **cmd, int step, int pre_fd)
{
	pid_t	pid;
	int		step_pipe[2];

	if (step == args->total_cmd)
		return ((void)close(args->io_fd[1]));
	if (step < args->total_cmd - 1)
		pipe(step_pipe);
	if (step == 1)
		close(args->io_fd[0]);
	pid = do_fork();
	if (pid == 0)
	{
		set_fd(args, step_pipe, step, pre_fd);
		if (cmd[step]->cmd_path == 0)
			exit(1);
		execve(cmd[step]->cmd_path, cmd[step]->cmd_info, args->envp);
		perror("execve failed");
		exit(1);
	}
	if (step < args->total_cmd - 1)
		close(step_pipe[1]);
	fork_exec(args, cmd, step + 1, step_pipe[0]);
	close(step_pipe[0]);
	do_wait(pid, args, step);
}

void	do_wait(pid_t pid, t_args *args, int step)
{
	if (step < args->total_cmd - 1)
	{
		if (wait(0) == -1)
			perror("wait() error");
	}
	else if (step == args->total_cmd - 1)
	{
		if (waitpid(pid, &(args->status_child), 0) == -1)
			perror("waitpid() error");
	}
}

void	set_fd(t_args *args, int *step_pipe, int step, int pre_fd)
{
	if (step != args->total_cmd - 1)
	{
		close(step_pipe[0]);
		close(args->io_fd[1]);
	}
	step_pipe[0] = pre_fd;
	if (step == args->total_cmd - 1)
		step_pipe[1] = args->io_fd[1];
	if (step_pipe[0] == -1 || step_pipe[1] == -1)
		exit(1);
	dup2(step_pipe[0], 0);
	close(step_pipe[0]);
	dup2(step_pipe[1], 1);
	close(step_pipe[1]);
}
