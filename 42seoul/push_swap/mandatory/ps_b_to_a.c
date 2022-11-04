/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:11:30 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/02 21:48:20 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_sort_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	size_t			big;
	size_t			n_big;

	while (s_b->use_size > 0)
	{
		big = most_big(s_b);
		if (s_b->use_size > 1)
			n_big = next_big(s_b);
		if (comp_idx(big, n_big, s_b) == n_big && s_b->use_size > 1)
		{
			push_a(s_a, s_b, op_lst, n_big);
			big = find_big(s_b);
			push_a(s_a, s_b, op_lst, big);
			op_sa(s_a, op_lst, 1);
		}
		else
			push_a(s_a, s_b, op_lst, big);
	}
}

void	push_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst, size_t big_idx)
{
	size_t	i;

	i = 0;
	if (big_idx <= s_b->use_size / 2)
	{
		while (big_idx > 0)
		{
			op_rb(s_b, op_lst, 1);
			big_idx--;
		}
	}
	else
	{
		i = s_b->use_size - big_idx;
		while (i > 0)
		{
			op_rrb(s_b, op_lst, 1);
			i--;
		}
	}
	op_pa(s_a, s_b, op_lst);
}

size_t	comp_idx(size_t big, size_t n_big, t_deque *stack)
{
	const size_t	size = stack->use_size;

	if (big <= size / 2)
	{
		if (n_big <= size / 2)
		{
			if (big < n_big)
				return (big);
		}
		else
		{
			if (big < size - n_big)
				return (big);
		}
		return (n_big);
	}
	else if (big > size / 2)
		return (comp_idx2(big, n_big, stack));
	return (0);
}

size_t	comp_idx2(size_t big, size_t n_big, t_deque *stack)
{
	const size_t	size = stack->use_size;

	if (n_big <= size / 2)
	{
		if (size - big < n_big)
			return (big);
	}
	else
	{
		if (big > n_big)
			return (big);
	}
	return (n_big);
}
