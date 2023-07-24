/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:17:46 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/24 20:52:12 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	write_error(char* str)
{
	while (*str)
		write(2, str++, 1);
}

void	cd_exe(int idx, int num, char** av) {

	if (num != 1)
	{
		write_error("error: cd: bad arguments\n");
		return ;
	}
	char* path = av[idx - num];
	if (chdir(path) == -1)
	{
		write_error("error: cd: cannot change directory to ");
		write_error(path);
		write_error("\n");
	}
}

int	exe_pipe(int idx, int num, char** av, char** env, int pre_fd)
{
	char* arr[99];
	int i = 0;
	arr[i] = av[idx - num];
	i++;
	while (idx - num < num) {
		arr[i] = av[(idx - num) + i];
		i++;
		idx++;
	}
	arr[i] = NULL;

	int _pipe[2];
	if (pipe(_pipe) == -1) {
		write_error("error: fatal\n");
		exit(1);
	}
	int pid = fork();
	if (pid == 0) {
		close(_pipe[0]);
		_pipe[0] = pre_fd;
		dup2(_pipe[0], 0);
		close(_pipe[0]);
		dup2(_pipe[1], 1);
		close(_pipe[1]);
		execve(arr[0], arr, env);
		write_error("error: cannot execute ");
		write_error(arr[0]);
		write_error("\n");
		exit(1);
	}
	else {
		if (pre_fd > 0)
			close(pre_fd);
		close(_pipe[1]);
	}
	return (_pipe[0]);
}

void	exe_last(int idx, int num, char** av, char** env, int pre_fd) {
	char* arr[99];
	for (int i = 0; i < 99; i++)
		arr[i] = NULL;
	int i = 0;
	arr[i] = av[idx - num];
	i++;
	int j = 1;
	while (j < num) {
		arr[i] = av[(idx - num) + i];
		idx++;
		i++;
		j++;
	}
	arr[i] = NULL;

	int pid = fork();
	if (pid == 0) {
		dup2(pre_fd, 0);
		close(pre_fd);
		execve(arr[0], arr, env);
		write_error("error: cannot execute ");
		write_error(arr[0]);
		write_error("\n");
		exit(1);
	}
}

int	main(int ac, char** av, char** env)
{
	if (ac < 2)
		exit(0);
	int	idx = 1;
	int pre_fd = 0;
	int	num = 0;
	while (av[idx] != NULL) {
		int num = 0;
		if (!strcmp(av[idx], ";"))
			idx++;
		else if (!strcmp(av[idx], "cd")) {
			idx++;
			while (av[idx] != NULL && strcmp(av[idx], ";")) {
				idx++;
				num++;
			}
			cd_exe(idx, num, av);
		}
		else if (strcmp(av[idx], "|") && strcmp(av[idx], ";")) {
			while (av[idx] != NULL && (strcmp(av[idx], "|") && strcmp(av[idx], ";"))) {
				idx++;
				num++;
			}
			if (av[idx] != NULL && !strcmp(av[idx], "|")) {
				pre_fd = exe_pipe(idx, num, av, env, pre_fd);
				idx++;
				num++;
			}
			else if (av[idx] == NULL || !strcmp(av[idx], ";")) {
				exe_last(idx, num, av, env, pre_fd);
				if (av[idx] != NULL && !strcmp(av[idx], ";"))
					idx++;
				num++;
				close(pre_fd);
			}
		}
	}
	for (int i = 0; i < num; i++)
		wait(0);
	exit (0);
}
