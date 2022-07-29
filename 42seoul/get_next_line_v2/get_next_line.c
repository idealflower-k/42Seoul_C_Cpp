/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IdealFlower <IdealFlower@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:39:17 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/30 01:24:49 by IdealFlower      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_list(t_list **list_head, int fd);
char	*ft_read_save(t_list *fd_list);
char	*ft_get_line(t_list *fd_list);
char	*ft_save(t_list *fd_list);
char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	static t_list	*list_head;
	t_list			*fd_list;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	fd_list = get_list(&(list_head), fd);
	if (!fd_list)
		return (0);
	fd_list->result = ft_read_save(fd_list);
	if (!fd_list->result)
		return (0);
	result = ft_get_line(fd_list);
	fd_list->result = ft_save(fd_list);
	return (result);
}

t_list	*get_list(t_list **list_head, int fd)
{
	t_list	*temp;

	temp = *list_head;
	if (*list_head == 0)
	{
		temp = ft_new_list(fd);
		if (!temp)
			return (0);
		*list_head = temp;
		return (temp);
	}
	while (temp)
	{
		if (temp ->fd == fd)
			break ;
		if (temp ->next == 0)
		{
			temp ->next = ft_new_list(fd);
			if (!(temp ->next))
				return (0);
			temp ->next ->before = temp;
		}
		temp = temp ->next;
	}
	return (temp);
}

char	*ft_read_save(t_list *fd_list)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	fd_list->read_byte = 1;
	while (!ft_strchr(fd_list, '\n') && fd_list->read_byte)
	{
		fd_list->read_byte = read(fd_list->fd, buf, BUFFER_SIZE);
		if (fd_list->read_byte == -1)
		{
			free(buf);
			ft_del_list(fd_list);
			return (0);
		}
		buf[fd_list->read_byte] = 0;
		fd_list->result = ft_strjoin(fd_list->result, buf);
	}
	free(buf);
	return (fd_list->result);
}

char	*ft_save(t_list *fd_list)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	while (fd_list->result[i] && fd_list->result[i] != '\n')
		i++;
	if (!fd_list->result[i])
	{
		free(fd_list->result);
		ft_del_list(fd_list);
		return (0);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(fd_list->result) - i + 1));
	if (!new)
		return (0);
	i++;
	j = 0;
	while (fd_list->result[i])
		new[j++] = fd_list->result[i++];
	new[j] = 0;
	free(fd_list->result);
	return (new);
}

char	*ft_get_line(t_list *fd_list)
{
	size_t	i;
	char	*line;

	if(!fd_list->result)
		return (0);
	i = 0;
	while (fd_list->result[i] && fd_list->result[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = -1;
	while (fd_list->result[++i] && fd_list->result[i] != '\n')
		line[i] = fd_list->result[i];
	if (fd_list->result[i] == '\n')
	{
		line[i] = fd_list->result[i];
		i++;
	}
	line[i] = 0;
	return (line);
}
