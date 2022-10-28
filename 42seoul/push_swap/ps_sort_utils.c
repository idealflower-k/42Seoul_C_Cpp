/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:17:20 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/28 23:18:26 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_stack(t_deque *stack, int *cp_stack)
{
	size_t	i;

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
		while (stack->nodes[i].data != (size_t)cp_stack[idx])
			idx++;
		stack->nodes[i].data = idx;
		i++;
	}
}
