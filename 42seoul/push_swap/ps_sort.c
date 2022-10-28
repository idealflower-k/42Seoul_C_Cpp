/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:50:16 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/28 18:03:18 by sanghwal         ###   ########seoul.kr  */
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
	show_stack(stack_a, stack_b);
	show_idx(stack_a, cp_stack);
}

int	*copy_stack(t_deque *stack, int *cp_stack)
{
	int	i;

	i = 0;
	while (i <= stack->rear)
	{
		cp_stack[i] = stack->nodes[i].data;
		i++;
	}
	return (cp_stack);
}

void	sort_copy(int *cp_stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (cp_stack[i])
	{
		j = i + 1;
		while (cp_stack[j])
		{
			if (cp_stack[i] > cp_stack[j])
			{
				tmp = cp_stack[i];
				cp_stack[i] = cp_stack[j];
				cp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	indexing_stack(int *cp_stack, t_deque *stack)
{
	size_t	idx;
	size_t	i;

	i = 0;
	idx = 0;
	while (i <= stack->rear)
	{
		idx = 0;
		while (stack->nodes[i].data != cp_stack[idx])
			idx++;
		stack->nodes[i].idx = idx;
		i++;
	}
}
