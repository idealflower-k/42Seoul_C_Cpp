/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:59:17 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/19 15:10:52 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_lst;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		cur_lst = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = cur_lst;
	}
	*lst = 0;
}
