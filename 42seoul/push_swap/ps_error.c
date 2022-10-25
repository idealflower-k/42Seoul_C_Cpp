/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:33:40 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/25 17:19:40 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(int err)
{
	if (err == 1)
		write(1, "ERROR\n", 6);
	exit(1);
}

void	free_stack(t_deque *stack)
{
	if (!stack)
	{
		if (!stack->nodes)
			free(stack->nodes);
		free(stack);
	}
}

void	free_lst(t_split *head)
{
	t_split	*tmp;
	t_split	*del;

	tmp = head;
	while (tmp != 0)
	{
		del = tmp;
		if (tmp->next != 0)
			tmp = tmp->next;
		else
			break ;
		free(tmp);
	}
}
