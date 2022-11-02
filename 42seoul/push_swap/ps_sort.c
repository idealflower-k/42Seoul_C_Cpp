/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:50:16 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/02 14:23:51 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_oper	*do_sort(t_deque *stack_a, t_deque *stack_b)
{
	t_oper	*op_lst;

	op_lst = 0;
	op_lst = add_op(op_lst, 0);
	if (stack_a->use_size < 6)
		small_sort(stack_a, stack_b, op_lst);
	else
		hourglass_sort(stack_a, stack_b, op_lst);
	return (op_lst);
}

t_oper	*add_op(t_oper *op_lst, char *op)
{
	t_oper	*tmp;
	t_oper	*new;

	if (op == 0)
	{
		new = (t_oper *)malloc(sizeof(t_oper));
		if (!new)
			handle_error(0);
		new->next = 0;
		new->op = 0;
		return (new);
	}
	else
	{
		tmp = op_lst;
		while (tmp->next != 0)
			tmp = tmp->next;
		new = (t_oper *)malloc(sizeof(t_oper));
		if (!new)
			handle_error(0);
		tmp->next = new;
		new->next = 0;
		new->op = op;
	}
	return (op_lst);
}

size_t	set_chunk(size_t capacity)
{
	size_t	chunk;

	if (capacity <= 14)
		chunk = capacity / 2;
	else
		chunk = (size_t)(0.000000053 * (capacity * capacity) \
			+ (0.03 * (capacity)) + 14.5);
	return (chunk);
}

void	hourglass_sort(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	make_hourglass(s_a, s_b, op_lst);
	make_sort_a(s_a, s_b, op_lst);
}
