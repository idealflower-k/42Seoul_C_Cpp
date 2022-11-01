/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:53:59 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/01 21:47:51 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sort(t_deque *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->use_size)
	{
		if (i == stack->nodes[i].data)
			i++;
		else
			return ;
	}
	if (i == stack->use_size)
		exit(0);
}
