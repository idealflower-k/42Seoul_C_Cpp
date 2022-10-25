/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:22:23 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/25 20:41:20 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_deque *stack_a)
{
	dq_push_rear(stack_a, dq_pop_front(stack_a));
}

void	op_rb(t_deque *stack_b)
{
	dq_push_rear(stack_b, dq_pop_front(stack_b));
}

void	op_rr(t_deque *stack_a, t_deque *stack_b)
{
	op_ra(stack_a);
	op_rb(stack_b);
}