/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:33:14 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/02 21:48:45 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	if (s_a->use_size == 2)
		sort_two(s_a, op_lst);
	else if (s_a->use_size == 3)
		sort_three(s_a, op_lst, 3);
	else if (s_a->use_size == 4)
		sort_four(s_a, s_b, op_lst);
	else
		sort_five(s_a, s_b, op_lst);
}

void	sort_two(t_deque *s_a, t_oper *op_lst)
{
	if (s_a->nodes[s_a->front].idx > s_a->nodes[s_a->rear].idx)
		op_sa(s_a, op_lst, 1);
}

void	sort_three(t_deque *s_a, t_oper *op_lst, size_t num)
{
	const size_t	front = s_a->nodes[s_a->front].idx;
	const size_t	rear = s_a->nodes[s_a->rear].idx;
	const size_t	f_val = num - 3;
	const size_t	m_val = num - 2;
	const size_t	r_val = num - 1;

	if (front == f_val && rear == m_val)
	{
		op_rra(s_a, op_lst, 1);
		op_sa(s_a, op_lst, 1);
	}
	else if (front == m_val && rear == r_val)
		op_sa(s_a, op_lst, 1);
	else if (front == m_val && rear == f_val)
		op_rra(s_a, op_lst, 1);
	else if (front == r_val && rear == m_val)
		op_ra(s_a, op_lst, 1);
	else if (front == r_val && rear == f_val)
	{
		op_sa(s_a, op_lst, 1);
		op_rra(s_a, op_lst, 1);
	}
}

void	sort_four(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	while (s_a->nodes[s_a->front].idx != 0)
		op_ra(s_a, op_lst, 1);
	op_pb(s_a, s_b, op_lst);
	sort_three(s_a, op_lst, 4);
	op_pa(s_a, s_b, op_lst);
}

void	sort_five(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	size_t	i;

	i = 0;
	while (i <= 5)
	{
		if (s_a->nodes[s_a->front].idx <= 1)
			op_pb(s_a, s_b, op_lst);
		else
			op_ra(s_a, op_lst, 1);
		i++;
	}
	if (s_b->nodes[s_b->front].idx < s_b->nodes[s_b->rear].idx)
		op_sb(s_b, op_lst, 1);
	sort_three(s_a, op_lst, 5);
	op_pa(s_a, s_b, op_lst);
	op_pa(s_a, s_b, op_lst);
}
