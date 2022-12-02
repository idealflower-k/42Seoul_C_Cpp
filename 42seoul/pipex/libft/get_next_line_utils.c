/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:06:07 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/02 19:35:09 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strchr(t_gnl_list *list, char c)
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

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *dst, char *src)
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
	result = (char *)malloc((gnl_strlen(dst) + gnl_strlen(src)) + 1);
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

t_gnl_list	*gnl_new_list(int fd)
{
	t_gnl_list	*new;

	new = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (!new)
		return (0);
	new->fd = fd;
	new->next = 0;
	new->result = 0;
	new->read_byte = 1;
	return (new);
}

char	*gnl_del_list(t_gnl_list *list, t_gnl_list **head)
{
	t_gnl_list	*temp;

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
