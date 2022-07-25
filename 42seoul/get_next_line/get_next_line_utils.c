/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:16:46 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/25 20:53:35 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*find_lst(t_list *lst, int fd);
static t_list	*ft_lstnew(void *fd);

static t_list	*find_lst(t_list *lst, int fd)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp -> index == fd)
			break ;
		if (temp -> next == 0)
		{
			temp -> next = ft_lstnew(fd);
		}
		temp = temp -> next;
	}
	return (temp);
}

static t_list	*ft_lstnew(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new -> index = fd;
	new -> buf = 0;
	new -> next = 0;
	return (new);
}
