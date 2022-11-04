/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:53:59 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/04 20:37:12 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_sort(t_deque *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->use_size)
	{
		if (i == stack->nodes[(stack->front + i) % stack->capacity].idx)
			i++;
		else
			return (0);
	}
	return (1);
}
