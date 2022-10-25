/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:50:16 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/25 19:09:39 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort(t_deque *stack_a)
{
	t_deque	*stack_b;

	stack_b = deque_creat(stack_a->capacity - 1);
	if (!stack_b)
	{
		free_stack(stack_a);
		handle_error(1);
	}
}
