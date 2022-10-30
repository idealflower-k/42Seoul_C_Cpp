/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:50:16 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/30 17:33:13 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_deque *stack_a)
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
	// write_oper(do_sort(stack_a, stack_b));
	do_sort(stack_a, stack_b);
	show_stack(stack_a, stack_b);
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

	chunk = (size_t)(0.000000053 * (capacity * capacity) \
		+ (0.03 * (capacity)) + 14.5);
	printf("chunk = %zu\n", chunk);
	return (chunk);
}

void	hourglass_sort(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	make_hourglass(s_a, s_b, op_lst);
	// make_sorted_a(s_a, s_b, op_lst);
	b_to_a(s_a, s_b, op_lst);
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
			if (i < s_a->capacity / 2 && i >= 0)
				op_rra(s_a, op_lst, 1);
			else
				op_ra(s_a, op_lst, 1);
		}
		show_stack(s_a, s_b);
	}
}

size_t	get_front(t_deque *stack)
{
	return (stack->nodes[stack->front].data);
}

void	make_sorted_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst)
{
	size_t	front;
	size_t	rear;

	while (s_b->use_size != 0)
	{
		front = s_b->nodes[s_b->front].data;
		rear = s_b->nodes[s_b->rear].data;
		if (front > rear)
			op_pa(s_a, s_b, op_lst);
		else if (front < rear)
		{
			op_rrb(s_b, op_lst, 1);
			op_pa(s_a, s_b, op_lst);
		}
		else
			op_pa(s_a, s_b, op_lst);
	}
}

void	write_oper(t_oper *op_lst)
{
	t_oper	*tmp;

	tmp = op_lst->next;
	while (tmp->next != 0)
	{
		printf("%s\n", tmp->op);
		tmp = tmp->next;
	}
}


void	b_rr(t_deque *deque_b, size_t *position, size_t *top_num, t_oper *op_lst)
{
	op_rrb(deque_b, op_lst, 1);
	*top_num = deque_b->nodes[deque_b->front].data;
	(*position)++;
}

void	b_r(t_deque *deque_b, size_t *position, size_t *top_num, t_oper *op_lst)
{
	op_rb(deque_b, op_lst, 1);
	*top_num = deque_b->nodes[deque_b->front].data;
	(*position)--;
}

void	find_big_idx(t_node *node, size_t *size, size_t *big_idx)
{
	size_t	i;

	i = 0;
	while (node != NULL)
	{
		if (node[i].data == (*size) - 1)
			break ;
		(*big_idx)++;
		i++;
	}
}

void	b_to_a(t_deque *deque_a, t_deque *deque_b, t_oper *op_lst)
{
	size_t		top_num;
	size_t		mid_num;
	size_t		big_idx;
	size_t		size;
	t_node		*node;

	size = deque_b->capacity;
	while (size > 0)
	{
		big_idx = 0;
		node = deque_b->nodes;
		top_num = deque_b->nodes[deque_b->front].data;
		find_big_idx(node, &size, &big_idx);
		mid_num = size / 2;
		if (big_idx > mid_num)
			while (big_idx < size)
				b_rr(deque_b, &big_idx, &top_num, op_lst);
		else if (big_idx <= mid_num)
			while (big_idx > 0)
				b_r(deque_b, &big_idx, &top_num, op_lst);
		op_pa(deque_a, deque_b, op_lst);
		size--;
	}
}
