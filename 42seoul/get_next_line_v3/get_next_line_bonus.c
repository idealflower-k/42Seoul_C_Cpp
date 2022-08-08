/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:03:58 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/08 21:10:04 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd);
char	*ft_read_save(t_list *list);
char	*ft_get_line(t_list *list);
char	*ft_save(t_list *list, t_list **head);
t_list	*get_list(t_list **list_head, int fd);

char	*get_next_line(int fd)
{
	static t_list	*list_head;
	t_list			*list;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	list = get_list(&(list_head), fd);
	if (!list)
		return (0);
	if (!ft_read_save(list))
		return (ft_del_list(list, &list_head));
	result = ft_get_line(list);
	if (!result)
		return (ft_del_list(list, &list_head));
	if (!ft_save(list, &list_head))
		return (ft_del_list(list, &list_head));
	return (result);
}

t_list	*get_list(t_list **list_head, int fd)
{
	t_list	*temp;

	if (*list_head == 0)
		*list_head = ft_new_list(fd);
	temp = *list_head;
	while (temp && temp->fd != fd)
	{
		if (temp->next == 0)
		{
			temp->next = ft_new_list(fd);
			if (!temp->next)
				return (0);
		}
		temp = temp->next;
	}
	if (read(fd, NULL, 0) < 0)
		return ((t_list *)ft_del_list(temp, list_head));
	return (temp);
}

char	*ft_read_save(t_list *list)
{
	while (!ft_strchr(list, '\n') && list->read_byte > 0)
	{
		list->read_byte = read(list->fd, list->buff, BUFFER_SIZE);
		if (list->read_byte == -1)
			return (0);
		else if (list->read_byte == 0)
		{
			if (list->result != 0 && list->result[0] == 0)
				return (0);
			break ;
		}
		list->buff[list->read_byte] = 0;
		list->result = ft_strjoin(list->result, list->buff);
	}
	return (list->result);
}

char	*ft_get_line(t_list *list)
{
	char	*line;
	size_t	i;

	i = 0;
	if (list->result[0] == 0)
		return (0);
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

char	*ft_save(t_list *list, t_list **head)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	if (list->read_byte == 0)
	{
		ft_del_list(list, head);
		return (list->buff);
	}
	while (list->result[i] != '\n')
		i++;
	new = (char *)malloc(ft_strlen(list->result) - i);
	i++;
	j = 0;
	while (new && list->result[i])
		new[j++] = list->result[i++];
	free(list->result);
	// list->result = 0; // 왜 이걸 넣으면 널체크를 못하는 거야...
	if (new)
	{
		new[j] = 0;
		list->result = new;
	}
	return (new);
}
