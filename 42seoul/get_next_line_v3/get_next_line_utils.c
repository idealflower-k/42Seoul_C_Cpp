/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IdealFlower <IdealFlower@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:06:07 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/09 13:10:56 by IdealFlower      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_del_list(t_list *list, t_list **head);
size_t	ft_strchr(t_list *list, char c);
size_t	ft_strlen(char *str);
t_list	*ft_new_list(int fd);
char	*ft_strjoin(char *dst, char *src);

size_t	ft_strchr(t_list *list, char c)
{
	size_t	i;

	if (!list->result)
		return (0);
	i = 0;
	while (list->result[i])
	{
		if (list->result[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *dst, char *src)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!dst)
	{
		dst = (char *)malloc(sizeof(char));
		if (!dst)
			return (0);
		dst[0] = 0;
	}
	result = (char *)malloc((ft_strlen(dst) + ft_strlen(src)) + 1);
	i = -1;
	while (result && dst[++i] != 0)
		result[i] = dst[i];
	j = 0;
	while (result && src[j] != 0)
		result[i++] = src[j++];
	if (result)
		result[i] = 0;
	free(dst);
	return (result);
}

t_list	*ft_new_list(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->fd = fd;
	new->before = 0;
	new->next = 0;
	new->result = 0;
	new->read_byte = 1;
	return (new);
}

char	*ft_del_list(t_list *list, t_list **head)
{
	t_list	*temp;

	if (list->result != 0)
		free(list->result);
	list->result = 0;
	if (*head == list)
	{
		*head = list->next;
		free(list);
		return (0);
	}
	temp = *head;
	while (temp->next != list)
		temp = temp->next;
	temp->next = list->next;
	free(list);
	return (0);
}
