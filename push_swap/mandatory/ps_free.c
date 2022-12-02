/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:22:00 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/05 14:37:38 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_oper_lst(t_oper *op_lst)
{
	t_oper	*tmp;
	t_oper	*del;

	del = op_lst;
	while (del != 0)
	{
		tmp = del->next;
		free(del);
		del = tmp;
	}
}

void	free_splited(char **splited)
{
	size_t	i;

	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
	return ;
}

void	free_split_lst(t_split *head)
{
	t_split	*tmp;
	t_split	*del;

	del = head;
	while (del != 0)
	{
		tmp = del->next;
		free(del);
		del = tmp;
	}
}
