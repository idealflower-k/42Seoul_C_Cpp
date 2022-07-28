/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:12:23 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/28 16:34:51 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{	
	static t_list	*lst_head;
	char			*result;
	t_list			*fd_lst;

	if (fd < 0)
		return (0);
	fd_lst = find_lst(&(lst_head), fd);
	result = 0;
	if (fd_lst ->old_buf != 0 && ft_strchr(fd_lst -> old_buf, '\n'))
		result = ft_resultdup(fd_lst -> old_buf);
	else if (ft_strlen(fd_lst -> old_buf) < BUFFER_SIZE)
	{
		result = fd_lst -> old_buf;
		ft_delnode(&(lst_head), fd);
	}
	else
		read_split(fd, fd_lst);
	return (result);
}

void	read_split(int fd, t_list *fd_lst)
{
	char	*buf;
	ssize_t	read_byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_byte = read(fd, buf, BUFFER_SIZE);
	if (read_byte == -1)
		return ;
	if (fd_lst ->old_buf == 0)
		fd_lst ->old_buf = buf;
	else
		fd_lst ->old_buf = ft_strjoin(fd_lst -> old_buf, buf);
	free(buf);
	get_next_line(fd);
}

char	*ft_resultdup(char *old_buf)
{
	size_t	i;
	char	*temp;
	char	*save_old_buf;

	i = 0;
	save_old_buf = old_buf;
	while (save_old_buf[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	temp[i] = '\n';
	temp[i + 1] = 0;
	old_buf += (i + 1);
	while (i >= 0)
	{
		temp[i] = save_old_buf[i];
		i--;
	}
	return (temp);
}

void	ft_delnode(t_list **lst_head, int fd)
{
	t_list	*temp;
	t_list	*del_lst;

	temp = *lst_head;
	if (temp -> fd == fd)
	{
		*lst_head = temp -> next;
		free(temp);
		return ;
	}
	while (temp -> next -> fd != fd)
		temp = temp -> next;
	del_lst = temp -> next;
	temp -> next = del_lst ->next;
	free(del_lst);
}

#include <unistd.h> // open, read
#include <stdio.h> // printf
#include <fcntl.h> // read dhqtusdls O_RDONLY 등

int main(void)
{
	int fd;
	char *temp;

	fd = open("test1.txt", O_RDONLY);
	temp = get_next_line(fd);

	printf("%s", temp);
}