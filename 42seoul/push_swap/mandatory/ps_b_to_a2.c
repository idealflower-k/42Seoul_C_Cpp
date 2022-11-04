/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_to_a2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:14:32 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/02 21:48:22 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	most_big(t_deque *stack)
{
	size_t	idx;
	size_t	big_idx;
	size_t	cnt;

	cnt = 0;
	idx = stack->front;
	big_idx = stack->use_size - 1;
	while (big_idx != stack->nodes[idx].idx)
	{
		if (idx == stack->capacity - 1)
			idx = 0;
		else
			idx++;
		cnt++;
	}
	return (cnt);
}

size_t	next_big(t_deque *stack)
{
	size_t	idx;
	size_t	big_idx;
	size_t	cnt;

	cnt = 0;
	idx = stack->front;
	big_idx = stack->use_size - 2;
	while (big_idx != stack->nodes[idx].idx)
	{
		if (idx == stack->capacity - 1)
			idx = 0;
		else
			idx++;
		cnt++;
	}
	return (cnt);
}

size_t	find_big(t_deque *stack)
{
	size_t	idx;
	size_t	big_idx;
	size_t	cnt;

	cnt = 0;
	idx = stack->front;
	big_idx = stack->use_size;
	while (big_idx != stack->nodes[idx].idx)
	{
		if (idx == stack->capacity - 1)
			idx = 0;
		else
			idx++;
		cnt++;
	}
	return (cnt);
}
