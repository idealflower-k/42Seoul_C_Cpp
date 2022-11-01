/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:33:14 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/01 18:16:23 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	if (s_a->use_size == 2)
		sort_two(s_a, s_b, op_lst);
	else if (s_a->use_size == 3)
		sort_three(s_a, s_b, op_lst);
	else if (s_a->use_size == 4)
		sort_four(s_a, s_b, op_lst);
	else
		sort_five(s_a, s_b, op_lst);
}

void	sort_two(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	if (s_a->nodes[s_a->front].data > s_a->nodes[s_a->rear].data)
		op_sa(s_a, op_lst, 1);
	else
		return ;
}

void	sort_three(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	const size_t	front = s_a->nodes[s_a->front].data;
	const size_t	mid = s_a->nodes[s_a->front + 1].data;
	const size_t	rear = s_a->nodes[s_a->rear].data;

	if (front == 0 && rear == 1)
	{
		op_rra(s_a, op_lst, 1);
		op_sa(s_a, op_lst, 1);
	}
	
}
void	sort_four(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
void	sort_five(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
