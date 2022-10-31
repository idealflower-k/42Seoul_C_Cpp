/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:50:16 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/31 15:15:11 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push_swap(t_deque *stack_a)
{
	t_deque	*stack_b;
	int		*sorted;
	int		*cp_stack;

	stack_b = deque_creat(stack_a->capacity);
	sorted = (int *)malloc(sizeof(int) * stack_a->capacity);
	cp_stack = (int *)malloc(sizeof(int) * stack_a->capacity);
	if (!stack_b || !sorted || !cp_stack)
		handle_error(1);
	sort_copy(copy_stack(stack_a, cp_stack));
	indexing_stack(cp_stack, stack_a);
	write_oper(do_sort(stack_a, stack_b));
}

t_oper	*do_sort(t_deque *stack_a, t_deque *stack_b)
{
	t_oper	*op_lst;

	op_lst = 0;
	op_lst = add_op(op_lst, 0);
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
	make_sorted_a(s_a, s_b, op_lst);
}

void	make_hourglass(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	size_t	i;

	i = 0;
	make_hourglass_utils(s_a, s_b, op_lst, i);
}
void	make_hourglass_utils(t_deque *s_a, t_deque *s_b, t_oper *op_lst, size_t i)
{
	const size_t	chunk = set_chunk(s_a->capacity);

	while (i < s_a->capacity)
	{
		if (get_front(s_a) <= i)
		{
			op_pb(s_a, s_b, op_lst);
			i++;
		}
		else if (get_front(s_a) > i && get_front(s_a) <= i + chunk)
		{
			op_pb(s_a, s_b, op_lst);
			op_rb(s_b, op_lst, 1);
			i++;
		}
		else if (get_front(s_a) > i + chunk)
		{
			op_ra(s_a, op_lst, 1);
		}
	}
}

size_t	get_front(t_deque *stack)
{
	return (stack->nodes[stack->front].data);
}

void	make_sorted_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	size_t	big_idx;

	while (s_b->use_size > 0)
	{
		big_idx = get_big(s_b);
		push_a(s_a, s_b, op_lst, big_idx);
	}
}

void	push_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst, size_t big_idx)
{
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
		while (big_idx > 0)
		{
			op_rrb(s_b, op_lst, 1);
			big_idx--;
		}
	}
	op_pa(s_a, s_b, op_lst);
}

size_t	get_big(t_deque *stack)
{
	size_t	idx;
	size_t	big_idx;
	size_t	cnt;

	cnt = 0;
	idx = stack->front;
	big_idx = stack->use_size - 1;
	while (big_idx != stack->nodes[idx].data)
	{
		if (idx == stack->capacity -1)
			idx = 0;
		else
			idx++;
		cnt++;
	}
	return (cnt);
}

void	write_oper(t_oper *op_lst)
{
	t_oper	*tmp;

	tmp = op_lst->next;
	while (tmp != 0)
	{
		printf("%s\n", tmp->op);
		tmp = tmp->next;
	}
}
