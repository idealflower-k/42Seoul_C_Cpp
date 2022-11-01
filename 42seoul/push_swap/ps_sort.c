/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:50:16 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/01 17:24:13 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push_swap(t_deque *stack_a)
{
	t_deque	*stack_b;
	int		*sorted;
	size_t		*cp_stack;

	stack_b = deque_creat(stack_a->capacity);
	sorted = (int *)malloc(sizeof(int) * stack_a->capacity);
	cp_stack = (size_t *)malloc(sizeof(size_t) * stack_a->capacity);
	if (!stack_b || !sorted || !cp_stack)
		handle_error(1);
	sort_copy(copy_stack(stack_a, cp_stack), stack_a->capacity);
	indexing_stack(cp_stack, stack_a);
	write_oper(do_sort(stack_a, stack_b));
	//do_sort(stack_a, stack_b);
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
	make_hourglass_utl(s_a, s_b, op_lst, i);
}

void	make_hourglass_utl(t_deque *s_a, t_deque *s_b, t_oper *op_lst, size_t i)
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
			i++;
			if (get_front(s_a) > i + chunk)
				op_rr(s_a, s_b, op_lst);
			else
				op_rb(s_b, op_lst, 1);
		}
		else if (get_front(s_a) > i + chunk)
			check_rra(s_a, op_lst, i + chunk);
	}
}

void	check_rra(t_deque *s_a, t_oper *op_lst, size_t ichunk)
{
	if (!(get_rear(s_a) > ichunk))
		op_rra(s_a, op_lst, 1);
	else if ((get_rear(s_a) > ichunk))
		op_ra(s_a, op_lst, 1);
}

size_t	get_rear(t_deque *stack)
{
	return (stack->nodes[stack->rear].data);
}

size_t	get_front(t_deque *stack)
{
	return (stack->nodes[stack->front].data);
}

void	make_sorted_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
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

size_t	find_big(t_deque *stack)
{
	size_t	idx;
	size_t	big_idx;
	size_t	cnt;

	cnt = 0;
	idx = stack->front;
	big_idx = stack->use_size;
	while (big_idx != stack->nodes[idx].data)
	{
		if (idx == stack->capacity - 1)
			idx = 0;
		else
			idx++;
		cnt++;
	}
	return (cnt);
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

size_t	most_big(t_deque *stack)
{
	size_t	idx;
	size_t	big_idx;
	size_t	cnt;

	cnt = 0;
	idx = stack->front;
	big_idx = stack->use_size - 1;
	while (big_idx != stack->nodes[idx].data)
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
	while (big_idx != stack->nodes[idx].data)
	{
		if (idx == stack->capacity - 1)
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
