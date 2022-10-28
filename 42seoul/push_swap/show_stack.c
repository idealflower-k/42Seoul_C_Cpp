/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:49:19 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/28 18:03:57 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_deque *stack_a, t_deque *stack_b)
{
	printf("stack_a use %zu : ", stack_a->use_size);

	int	cnt = 0;
	int	idx = stack_a->front;

	while (cnt < stack_a->use_size)
	{
		if (idx != 0 && ((idx % stack_a->capacity) == 0))
			idx = 0;
		printf("%d ", stack_a->nodes[idx].data);
		idx++;
		cnt++;
	}

	printf("\nstack_b use %zu : ", stack_b->use_size);

	cnt = 0;
	idx = stack_b->front;

	while (cnt < stack_b->use_size)
	{
		if (idx != 0 && ((idx % stack_b->capacity) == 0))
			idx = 0;
		printf("%d ", stack_b->nodes[idx].data);
		idx++;
		cnt++;
	}
	printf("\n");
	printf("\n");
}

void	show_idx(t_deque *stack, int *cp_stack)
{
	printf("sorted : ");
	for (int i = 0; cp_stack[i]; i++)
		printf("%d[%d], ", cp_stack[i], i);
	printf("\n");
	
	printf("stack_idx : ");
	int	cnt = 0;
	int	idx = stack->front;
	while (cnt < stack->use_size)
	{
		if (idx != 0 && ((idx % stack->capacity) == 0))
			idx = 0;
		printf("%d[%zu], ", stack->nodes[idx].data, stack->nodes[idx].idx);
		idx++;
		cnt++;
	}
}