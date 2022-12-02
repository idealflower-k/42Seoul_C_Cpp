/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operator1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:48:45 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/04 20:44:10 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	op_sa(t_deque *stack_a)
{
	int	tmp1;
	int	tmp2;

	tmp1 = 0;
	tmp2 = 0;
	if (stack_a->use_size >= 2)
	{
		tmp1 = dq_pop_front(stack_a);
		tmp2 = dq_pop_front(stack_a);
		dq_push_front(stack_a, tmp1);
		dq_push_front(stack_a, tmp2);
	}
	return ;
}

void	op_sb(t_deque *stack_b)
{
	int	tmp1;
	int	tmp2;

	tmp1 = 0;
	tmp2 = 0;
	if (stack_b->use_size >= 2)
	{
		tmp1 = dq_pop_front(stack_b);
		tmp2 = dq_pop_front(stack_b);
		dq_push_front(stack_b, tmp1);
		dq_push_front(stack_b, tmp2);
	}
	return ;
}

void	op_ss(t_deque *stack_a, t_deque *stack_b)
{
	op_sa(stack_a);
	op_sb(stack_b);
	return ;
}

void	op_pa(t_deque *stack_a, t_deque *stack_b)
{
	if (stack_b->use_size > 0)
		dq_push_front(stack_a, dq_pop_front(stack_b));
	return ;
}

void	op_pb(t_deque *stack_a, t_deque *stack_b)
{
	if (stack_a->use_size > 0)
		dq_push_front(stack_b, dq_pop_front(stack_a));
	return ;
}
