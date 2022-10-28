/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:30:14 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/28 22:12:38 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_node(t_split *head, int num)
{
	t_split	*node;
	t_split	*tmp;

	tmp = head;
	node = (t_split *)malloc(sizeof(t_split));
	if (!node)
		handle_error(1);
	node->num = num;
	node->len = 0;
	node->next = 0;
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->next = node;
	return ;
}

int	check_overlap(t_split *head, int num)
{
	t_split	*tmp;

	tmp = head->next;
	while (tmp != 0)
	{
		if (tmp->num == num)
			handle_error(1);
		tmp = tmp->next;
	}
	return (1);
}

t_split	*lst_creat(void)
{
	t_split	*head;

	head = (t_split *)malloc(sizeof(t_split));
	if (!head)
		handle_error(1);
	head->num = 0;
	head->next = 0;
	head->len = 0;
	return (head);
}
