/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:17:20 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/31 17:27:14 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	*copy_stack(t_deque *stack, size_t *cp_stack)
{
	size_t	i;

	i = 0;
	while (i < stack->use_size)
	{
		cp_stack[i] = stack->nodes[i].data;
		i++;
	}
	return (cp_stack);
}

void	sort_copy(size_t *cp_stack, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
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

void	indexing_stack(size_t *cp_stack, t_deque *stack)
{
	size_t	idx;
	size_t	i;

	i = 0;
	idx = 0;
	while (i <= stack->rear)
	{
		idx = 0;
		while (stack->nodes[i].data != (size_t)cp_stack[idx])
			idx++;
		stack->nodes[i].data = idx;
		i++;
	}
}
