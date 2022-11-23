/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:59:15 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/23 17:40:19 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (!result)
		exit(1);
	return (result);
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	out_file_open(t_args *args)
{
	args->io_fd[1] = \
		open(args->av[args->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (args->io_fd[1] == -1)
		perror("outfile open() error");
}
