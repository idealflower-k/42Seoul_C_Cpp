/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:48:45 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/25 20:28:12 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_deque *stack_a)
{
	int				tmp;
	const size_t	front = stack_a->front;

	tmp = stack_a->nodes[front].data;
	if (stack_a->capacity % stack_a->front == 0)
	{
		stack_a->nodes[front].data = stack_a->nodes[0].data;
		stack_a->nodes[0].data = tmp;
	}
	else
	{
		stack_a->nodes[front].data = stack_a->nodes[front + 1].data;
		stack_a->nodes[front + 1].data = tmp;
	}
}

void	op_sb(t_deque *stack_b)
{
	int				tmp;
	const size_t	front = stack_b->front;

	tmp = stack_b->nodes[front].data;
	if (stack_b->capacity % stack_b->front == 0)
	{
		stack_b->nodes[front].data = stack_b->nodes[0].data;
		stack_b->nodes[0].data = tmp;
	}
	else
	{
		stack_b->nodes[front].data = stack_b->nodes[front + 1].data;
		stack_b->nodes[front + 1].data = tmp;
	}
}

void	op_ss(t_deque *stack_a, t_deque *stack_b)
{
	op_sa(stack_a);
	op_sb(stack_b);
}

void	op_pa(t_deque *stack_a, t_deque *stack_b)
{
	dq_push_front(stack_a, dq_pop_front(stack_b));
}

void	op_pb(t_deque *stack_a, t_deque *stack_b)
{
	dq_push_front(stack_b, dq_pop_front(stack_a));
}
