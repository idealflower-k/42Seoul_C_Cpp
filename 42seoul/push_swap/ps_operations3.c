/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:41:57 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/25 20:45:28 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_deque *stack_a)
{
	dq_push_front(stack_a, dq_pop_rear(stack_a));
}

void	op_rrb(t_deque *stack_b)
{
	dq_push_front(stack_b, dq_pop_rear(stack_b));
}

void	op_rrr(t_deque *stack_a, t_deque *stack_b)
{
	op_ra(stack_a);
	op_rb(stack_b);
}
