/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:16:46 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/26 21:40:07 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_lst(t_list **lst, int fd);
t_list	*ft_lstnew(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *str);
ssize_t	ft_strchr(char const *str, char c);

t_list	*find_lst(t_list **lst, int fd)
{
	t_list	*temp;

	temp = *lst;
	if (!*lst)
	{
		temp = ft_lstnew(fd);
		if (!temp)
			return (0);
		*lst = temp;
		return (temp);
	}
	while (temp)
	{
		if (temp -> fd == fd)
			break ;
		if (temp -> next == 0)
		{
			temp -> next = ft_lstnew(fd);
			if (!(temp -> next))
				return (0);
		}
		temp = temp -> next;
	}
	return (temp);
}

t_list	*ft_lstnew(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new -> fd = fd;
	new -> old_buf = 0;
	new -> next = 0;
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	char			*temp;
	size_t			i;

	temp = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	i = 0;
	while (i < s1_len)
	{
		temp[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		temp[s1_len + i] = s2[i];
		i++;
	}
	temp[s1_len + i] = 0;
	return (temp);
}

size_t	ft_strlen(char const *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

ssize_t	ft_strchr(char const *str, char c)
{
	ssize_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
