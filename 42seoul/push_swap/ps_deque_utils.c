/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deque_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:18:34 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/26 15:28:39 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dq_push_front(t_deque *stack, int num)
{
	size_t	tmp;

	if (stack->use_size == 0)
		tmp = stack->front;
	else if (stack->front == 0)
		tmp = stack->capacity - 1;
	else
		tmp = stack->front - 1;
	stack->nodes[tmp].data = num;
	stack->front = tmp;
	stack->use_size++;
}

void	dq_push_rear(t_deque *stack, int num)
{
	size_t	tmp;

	if (stack->use_size == 0)
		tmp = stack->rear;
	else if (stack->rear == stack->capacity - 1)
		tmp = 0;
	else
		tmp = stack->rear + 1;
	stack->nodes[tmp].data = num;
	stack->rear = tmp;
	stack->use_size++;
	return ;
}

int	dq_pop_front(t_deque *stack)
{
	size_t	tmp;
	int		num;

	if (stack->front == stack->capacity - 1)
		tmp = 0;
	else
		tmp = stack->front + 1;
	num = stack->nodes[stack->front].data;
	if (stack->front != stack->rear)
		stack->front = tmp;
	stack->use_size--;
	return (num);
}

int	dq_pop_rear(t_deque *stack)
{
	size_t	tmp;
	int		num;

	if (stack->rear == 0)
		tmp = stack->capacity - 1;
	else
		tmp = stack->rear - 1;
	num = stack->nodes[stack->rear].data;
	if (stack->front != stack->rear)
		stack->rear = tmp;
	stack->use_size--;
	return (num);
}
