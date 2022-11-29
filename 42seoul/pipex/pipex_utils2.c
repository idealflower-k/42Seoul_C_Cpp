/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:19:40 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/29 21:20:16 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_temp_file(t_args *arg_info)
{
	char	*tmp;
	char	*gnl;
	int		num;

	tmp = "/tmp/pipex_tmp0";
	num = 0;
	while (access(tmp, F_OK) == 0)
	{
		tmp = ft_strjoin(tmp, ft_itoa(num++));
		num %= 10; // 수정 필요 , 9 다음 90 부터  시작할듯...
	}
	arg_info->io_fd[0] = open(tmp, O_WRONLY | O_CREAT, 0644);
	if (arg_info->io_fd[0] == -1)
		perror("temp file open() error");
	write(1, "here_doc> ", 10);
	gnl = get_next_line(0);
	while (ft_strncmp(gnl, arg_info->av[2], ft_strlen(arg_info->av[2])))
	{
		if (write(arg_info->io_fd[0], gnl, ft_strlen(gnl)) == -1)
			perror("infile write error()");
		free(gnl);
		write(1, "here_doc> ", 10);
		gnl = get_next_line(0);
	}
	close(arg_info->io_fd[0]);
	arg_info->io_fd[0] = open(tmp, O_RDONLY);
	unlink(tmp);
}
