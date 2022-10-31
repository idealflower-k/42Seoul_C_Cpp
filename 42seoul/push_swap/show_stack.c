/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:49:19 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/31 17:20:22 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_deque *stack_a, t_deque *stack_b)
{
	printf("stack_a use %zu : ", stack_a->use_size);

	size_t	cnt = 0;
	int	idx = stack_a->front;

	while (cnt < stack_a->use_size)
	{
		if (idx != 0 && ((idx % stack_a->capacity) == 0))
			idx = 0;
		printf("%zu ", stack_a->nodes[idx].data);
		idx++;
		cnt++;
	}

	if (stack_b != 0)
	{
		printf("\nstack_b use %zu : ", stack_b->use_size);

		cnt = 0;
		idx = stack_b->front;

		while (cnt < stack_b->use_size)
		{
			if (idx != 0 && ((idx % stack_b->capacity) == 0))
				idx = 0;
			printf("%zu ", stack_b->nodes[idx].data);
			idx++;
			cnt++;
		}
	}
	printf("\n");
	printf("\n");
}

void	show_idx(t_deque *stack, size_t *cp_stack)
{
	printf("sorted : ");
	for (size_t i = 0; i < stack->use_size; i++)
		printf("%zu[%zu], ", cp_stack[i], i);
	printf("\n");

	printf("stack_idx : ");
	size_t	cnt = 0;
	int	idx = stack->front;
	while (cnt < stack->use_size)
	{
		if (idx != 0 && ((idx % stack->capacity) == 0))
			idx = 0;
		printf("%zu, ", stack->nodes[idx].data);
		idx++;
		cnt++;
	}
}