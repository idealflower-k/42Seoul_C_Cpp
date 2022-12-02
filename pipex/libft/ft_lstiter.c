/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:59:42 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/19 14:59:44 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur_lst;

	if (!lst || !f)
		return ;
	cur_lst = lst;
	while (cur_lst)
	{
		(*f)(cur_lst -> content);
		cur_lst = cur_lst -> next;
	}
}
