/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:49:05 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/23 19:22:55 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	t_cmd	**cmd_arr;
	t_args	*arg_info;

	if (ac < 5)
		ft_error("argument not enough : least 5 need");
	arg_info = ft_malloc(sizeof(t_args));
	arg_info->ac = ac;
	arg_info->av = av;
	arg_info->envp = envp;
	arg_info->status_child = 0;
	cmd_arr = parsing_av(ac - 3, av + 2, envp);
	arg_info->io_fd[0] = open(av[1], O_RDONLY);
	if (arg_info->io_fd[0] == -1)
		perror("infile open() error");
	fork_exec(arg_info, cmd_arr, 0, arg_info->io_fd[0]);
	exit(WEXITSTATUS(arg_info->status_child));
}

void	fork_exec(t_args *args, t_cmd **cmd, int step, int pre_fd)
{
	pid_t	pid;
	int		step_pipe[2];

	if (step == args->ac - 3)
		return ;
	if (step < args->ac - 4)
		pipe(step_pipe);
	if (step == 1)
		close(args->io_fd[0]);
	pid = do_fork();
	if (pid == 0)
	{
		set_fd(args, step_pipe, step, pre_fd);
		execve(cmd[step]->cmd_path, cmd[step]->cmd_info, args->envp);
	}
	if (step < args->ac - 4)
		close(step_pipe[1]);
	fork_exec(args, cmd, step + 1, step_pipe[0]);
	close(step_pipe[0]);
	do_wait(pid, args, step);
}

void	do_wait(pid_t pid, t_args *args, int step)
{
	if (step < args->ac - 4)
	{
		write(1, "<ac-4\n", 6);
		if (wait(0) == -1)
			perror("wait() error");
	}
	else if (step == args->ac - 4)
	{
		write(1, ">ac-4\n", 6);
		if (waitpid(pid, &(args->status_child), 0) == -1)
			perror("waitpid() error");
	}
}

pid_t	do_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		perror("fork() error");
	return (pid);
}

void	set_fd(t_args *args, int *step_pipe, int step, int pre_fd)
{
	if (step != args->ac - 4)
		close(step_pipe[0]);
	step_pipe[0] = pre_fd;
	dup2(step_pipe[0], 0);
	close(step_pipe[0]);
	if (step == args->ac - 4)
	{
		out_file_open(args);
		step_pipe[1] = args->io_fd[1];
	}
	dup2(step_pipe[1], 1);
	close(step_pipe[1]);
}
