/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:49:05 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/22 16:43:37 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	t_cmd_node	**cmd_arr;
	t_args		*arg_info;
	
	// if (ac < 5)
	// args error print
	arg_info = ft_malloc(sizeof(t_args));
	arg_info->ac = ac;
	arg_info->av = av;
	arg_info->envp = envp;
	cmd_arr = parsing_av(ac - 3, av + 2, envp);
	arg_info->file_fd[0] = open(av[1], O_RDONLY);
	recursive_fork(arg_info, cmd_arr, 0, arg_info->file_fd[0]);
	close(arg_info->file_fd[0]);
	close(arg_info->file_fd[1]);
	exit(0);
}

void	recursive_fork(t_args *arg_info, t_cmd_node **cmd_arr, int step, int pre_fd)
{
	pid_t	pid;

	if (step == arg_info->ac - 3)
		return ;
	if (step != arg_info->ac - 4)
		pipe(cmd_arr[step]->pipe);
	pid = fork();
	if (pid == 0)
	{
		if (step != arg_info->ac - 4)
			close(cmd_arr[step]->pipe[0]);
		cmd_arr[step]->pipe[0] = pre_fd;
		dup2(cmd_arr[step]->pipe[0], 0);
		close(cmd_arr[step]->pipe[0]);
		if (step == arg_info->ac - 4)
			cmd_arr[step]->pipe[1] = arg_info->file_fd[1];
		dup2(cmd_arr[step]->pipe[1], 1);
		close(cmd_arr[step]->pipe[1]);
		execve(cmd_arr[step]->cmd_path, cmd_arr[step]->cmd_info, arg_info->envp);
	}
	if (step != arg_info->ac -4)
		close(cmd_arr[step]->pipe[1]);
	if (step == arg_info->ac - 5)
		arg_info->file_fd[1] = open(arg_info->av[arg_info->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	recursive_fork(arg_info, cmd_arr, step + 1, cmd_arr[step]->pipe[0]);
	close(cmd_arr[step]->pipe[0]);
	wait(0);
	return ;
}
