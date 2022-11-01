/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:49:09 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/01 20:18:03 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*deque_creat(size_t size)
{
	t_deque	*stack;

	stack = (t_deque *)malloc(sizeof(t_deque));
	if (!stack)
		handle_error(1);
	stack->capacity = size;
	stack->front = 0;
	stack->rear = 0;
	stack->use_size = 0;
	stack->nodes = (t_node *)malloc(sizeof(t_node) * (stack->capacity));
	if (!stack->nodes)
		handle_error(1);
	return (stack);
}

void	fill_stack_a(t_deque *stack_a, t_split *head)
{
	t_split	*tmp;

	tmp = head->next;
	while (tmp)
	{
		stack_a->nodes[stack_a->rear].data = tmp->num;
		stack_a->rear++;
		stack_a->use_size++;
		tmp = tmp->next;
	}
	stack_a->rear--;
}
