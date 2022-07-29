/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:39:17 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/29 18:11:28 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_list(t_list **list_head, int fd);
t_list	*ft_new_list(int fd);
size_t	ft_strchr(t_list *fd_list, char c);
char	*ft_strjoin(char *dst, char *src);
void	ft_del_list(t_list *fd_list);
char	*ft_get_result(t_list *fd_list);
char	*ft_strdup(t_list *fd_list);
char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	static t_list	*list_head;
	t_list			*fd_list;
	char			*result;

	if (fd < 0)
		return (0);
	fd_list = get_list(&(list_head), fd);
	if (!fd_list)
		return (0);
	if (ft_strchr(fd_list, '\n'))
		result = ft_strdup(fd_list);
	else
		
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

t_list	*ft_new_list(int fd)
{
	t_list	*new;
	size_t	i;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new ->fd = fd;
	new ->next = 0;
	new ->offset = 0;
	new ->read_byte = 0;
	new ->before = 0;
	i = 0;
	while (i <= BUFFER_SIZE)
		new ->buff[i++] = 0;
	return (new);
}

size_t	ft_strchr(t_list *fd_list, char c)
{
	size_t	i;

	i = 0;
	while (fd_list->buff[i])
	{
		if (fd_list->buff[i] == c)
		{
			fd_list->offset = &fd_list->buff[i + 1];
			return (i);
		}
		i++;
	}
	return (0);
}

void	ft_del_list(t_list *fd_list)
{
	t_list	*temp;
	t_list	*del;

	temp = fd_list ->before;
	if (!temp)
	{
		del = fd_list;
		fd_list = fd_list ->next;
		free(del);
		return ;
	}
	temp ->next = fd_list ->next;
	free(fd_list);
}

char	*ft_get_result(t_list *fd_list)
{
	char	*result;
	size_t	result_len;

	return (result);
}

void	ft_make_result(char *result, t_list *fd_list)
{
	
}
char	*ft_strjoin(char *dst, char *src)
{
	size_t	dst_len;
	size_t	src_idx;

	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	src_idx = 0;
	while (src[src_idx])
		dst[dst_len++] = src[src_idx++];
	dst[dst_len] = 0;
}

char	*ft_strdup(t_list *fd_list)
{
	char			*line;
	size_t			i;
	size_t			j;
	const size_t	len = (fd_list->offset - fd_list->buff) + 1;

	line = (char *)malloc(sizeof(char) * len);
	i = 0;
	while (&fd_list->buff[i] != fd_list->offset)
	{
		line[i] = fd_list->buff[i];
		i++;
	}
	line[i] = 0;
	j = 0;
	while (fd_list->offset[j])
	{
		fd_list->buff[j] = fd_list->offset[j];
		j++;
	}
	return (line);
}
