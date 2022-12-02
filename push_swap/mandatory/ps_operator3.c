/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operator3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:41:57 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/04 19:35:22 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_deque *stack_a, t_oper *op_lst, int flag)
{
	if (stack_a->use_size >= 2)
		dq_push_front(stack_a, dq_pop_rear(stack_a));
	if (flag == 1 && op_lst != 0)
		add_op(op_lst, "rra");
	return ;
}

void	op_rrb(t_deque *stack_b, t_oper *op_lst, int flag)
{
	if (stack_b->use_size >= 2)
		dq_push_front(stack_b, dq_pop_rear(stack_b));
	if (flag == 1 && op_lst != 0)
		add_op(op_lst, "rrb");
	return ;
}

void	op_rrr(t_deque *stack_a, t_deque *stack_b, t_oper *op_lst)
{
	op_rra(stack_a, op_lst, 0);
	op_rrb(stack_b, op_lst, 0);
	if (op_lst != 0)
		add_op(op_lst, "rrr");
	return ;
}
