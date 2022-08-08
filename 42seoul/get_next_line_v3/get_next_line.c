/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:06:16 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/08 14:53:49 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
char	*ft_read_save(t_list *list);
char	*ft_get_line(t_list *list);
void	ft_save(t_list *list, t_list **head);
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
	list->result = ft_read_save(list);
	if (list->result == 0)
	{
		ft_del_list(list, &list_head);
		return (0);
	}
	result = ft_get_line(list);
	if (!result)
	{
		free(list->result);
		ft_del_list(list, &list_head);
		return (0);
	}
	ft_save(list, &list_head);
	return (result);
}

t_list	*get_list(t_list **list_head, int fd)
{
	t_list	*temp;

	temp = *list_head;
	if (*list_head == 0)
	{
		*list_head = ft_new_list(fd);
		if (!*list_head)
			return (0);
		return (*list_head);
	}
	while (temp)
	{
		if (temp->fd == fd)
			break ;
		if (temp->next == 0)
		{
			temp->next = ft_new_list(fd);
			if (!temp->next)
				return (0);
			temp->next->before = temp;
		}
		temp = temp->next;
	}
	return (temp);
}

char	*ft_read_save(t_list *list)
{
	while (!ft_strchr(list, '\n') && list->read_byte > 0)
	{
		list->read_byte = read(list->fd, list->buff, BUFFER_SIZE);
		if (list->read_byte == -1)
		{
			if (list->result != 0)
			{
				free(list->result);
				list->result = 0;
			}
			return (0);
		}
		else if (list->read_byte == 0)
		{
			if (list->result != 0 && list->result[0] == 0)
			{
				free(list->result);
				list->result = 0;
			}
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

void	ft_save(t_list *list, t_list **head)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	if (list->read_byte == 0)
	{
		free(list->result);
		ft_del_list(list, head);
		return ;
	}
	while (list->result[i] != '\n')
		i++;
	new = (char *)malloc(ft_strlen(list->result) - i);
	if (!new)
		return ;
	i++;
	j = 0;
	while (list->result[i])
		new[j++] = list->result[i++];
	new[j] = 0;
	free(list->result);
	list->result = new;
}
