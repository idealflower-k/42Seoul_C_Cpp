/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:06:16 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/02 19:34:58 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_gnl_list	*list_head;
	t_gnl_list			*list;
	char				*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	list = get_list(&(list_head), fd);
	if (!list)
		return (0);
	if (!gnl_read_save(list))
		return (gnl_del_list(list, &list_head));
	result = gnl_get_line(list);
	if (!result)
		return (gnl_del_list(list, &list_head));
	if (!gnl_save(list, &list_head))
		return (gnl_del_list(list, &list_head));
	return (result);
}

t_gnl_list	*get_list(t_gnl_list **list_head, int fd)
{
	t_gnl_list	*temp;

	if (*list_head == 0)
		*list_head = gnl_new_list(fd);
	temp = *list_head;
	while (temp && temp->fd != fd)
	{
		if (temp->next == 0)
		{
			temp->next = gnl_new_list(fd);
			if (!temp->next)
				return (0);
		}
		temp = temp->next;
	}
	if (temp && read(fd, NULL, 0) < 0)
		return ((t_gnl_list *)gnl_del_list(temp, list_head));
	return (temp);
}

char	*gnl_read_save(t_gnl_list *list)
{
	while (!gnl_strchr(list, '\n') && list->read_byte > 0)
	{
		list->read_byte = read(list->fd, list->buff, BUFFER_SIZE);
		if (list->read_byte == -1)
			return (0);
		else if (list->read_byte == 0)
			break ;
		list->buff[list->read_byte] = 0;
		list->result = gnl_strjoin(list->result, list->buff);
	}
	return (list->result);
}

char	*gnl_get_line(t_gnl_list *list)
{
	char	*line;
	size_t	i;

	i = 0;
	while (list->result[i] && list->result[i] != '\n')
		i++;
	if (list->result[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (0);
	i = -1;
	while (list->result[++i] && list->result[i] != '\n')
		line[i] = list->result[i];
	if (list->result[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*gnl_save(t_gnl_list *list, t_gnl_list **head)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	while (list->read_byte != 0 && list->result[i] != '\n')
		i++;
	if (list->read_byte == 0
		|| (list->result[i] == '\n' && list->result[i + 1] == 0))
	{
		gnl_del_list(list, head);
		return (list->buff);
	}
	new = (char *)malloc(gnl_strlen(list->result) - i);
	i++;
	j = 0;
	while (new && list->result[i])
		new[j++] = list->result[i++];
	free(list->result);
	if (new)
		new[j] = 0;
	list->result = new;
	return (list->result);
}
