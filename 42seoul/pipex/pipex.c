/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:49:05 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/30 21:33:25 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	t_cmd	**cmd_arr;
	t_args	*arg_info;

	if (ac < 5)
		ft_error("argument not enough : least 5 need");
	arg_info = set_arg_info(ac, av, envp);
	cmd_arr = open_infile(arg_info);
	arg_info->total_cmd = cmd_arr[0]->total_cmd;
	fork_exec(arg_info, cmd_arr, 0, arg_info->io_fd[0]);
	exit(WEXITSTATUS(arg_info->status_child));
}

t_cmd	**open_infile(t_args *arg_info)
{
	if (ft_strncmp(arg_info->av[1], "here_doc", 8) == 0)
	{
		make_temp_file(arg_info);
		return (parsing_av(arg_info->ac - 4, arg_info->av + 3, arg_info->envp));
	}
	else
	{
		arg_info->io_fd[0] = open(arg_info->av[1], O_RDONLY);
		if (arg_info->io_fd[0] == -1)
			perror("infile open() error");
		return (parsing_av(arg_info->ac - 3, arg_info->av + 2, arg_info->envp));
	}
}

void	fork_exec(t_args *args, t_cmd **cmd, int step, int pre_fd)
{
	pid_t	pid;
	int		step_pipe[2];

	if (step == args->total_cmd)
		return ;
	if (step < args->total_cmd - 1)
		pipe(step_pipe);
	if (step == 1)
		close(args->io_fd[0]);
	pid = do_fork();
	if (pid == 0)
	{
		set_fd(args, step_pipe, step, pre_fd);
		if (cmd[step]->cmd_path == 0)
			exit(0);
		execve(cmd[step]->cmd_path, cmd[step]->cmd_info, args->envp);
		perror("execve failed");
		exit(0);
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
		close(step_pipe[0]);
	step_pipe[0] = pre_fd;
	dup2(step_pipe[0], 0);
	close(step_pipe[0]);
	if (step == args->total_cmd - 1)
	{
		out_file_open(args);
		step_pipe[1] = args->io_fd[1];
	}
	dup2(step_pipe[1], 1);
	close(step_pipe[1]);
}
