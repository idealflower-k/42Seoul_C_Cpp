/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:50:16 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/28 23:58:02 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_deque *stack_a)
{
	t_deque	*stack_b;
	t_oper	*op_lst;
	int		*sorted;
	int		*cp_stack;

	stack_b = deque_creat(stack_a->capacity);
	sorted = (int *)malloc(sizeof(int) * stack_a->capacity);
	cp_stack = (int *)malloc(sizeof(int) * stack_a->capacity);
	if (!stack_b || !sorted || !cp_stack)
		handle_error(1);
	sort_copy(copy_stack(stack_a, cp_stack));
	indexing_stack(cp_stack, stack_a);
	op_lst = 0;
	op_lst = do_sort(stack_a, stack_b);
}

t_oper	*do_sort(t_deque *stack_a, t_deque *stack_b)
{
	t_oper	*op_lst;
	size_t	chunk;

	chunk = 0;
	stack_b = 0;
	op_lst = 0;
	chunk = set_chunk(stack_a->capacity);
	op_lst = add_op(op_lst, 0);

	return (op_lst);
}

t_oper	*add_op(t_oper *op_lst, char *op)
{
	t_oper	*tmp;
	t_oper	*new;

	if (op == 0)
	{
		op_lst = (t_oper *)malloc(sizeof(t_oper));
		if (!op_lst)
			handle_error(0);
		op_lst->next = 0;
		op_lst->op = 0;
		return (op_lst);
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

	chunk = (size_t)(0.000000053 * (capacity * capacity) \
		+ 0.03 * (capacity) + 14.5);
	printf("chunk = %zu\n", chunk);
	return (chunk);
}
