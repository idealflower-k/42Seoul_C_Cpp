/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:24:32 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/06 19:57:02 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "deque.h"
#include "defines.h"
#include "meta.h"
#include "utils.h"

void	*dq_peek_front(const t_deque *dque)
{
	if (dque->use_size)
		return (dque->nodes[dque->front]);
	else
		return (NULL);
}

void	*dq_peek_rear(const t_deque *dque)
{
	if (dque->use_size)
		return (dque->nodes[dque->rear]);
	else
		return (NULL);
}

void	dq_free(const t_deque *dque)
{
	size_t	i;

	i = 0;
	if (dque == NULL)
		return ;
	while (i < dque->use_size)
	{
		free(dque->nodes[(i + dque->front) % dque->capacity]);
		i++;
	}
	free(dque->nodes);
	free((void *)dque);
}

void	dq_clear(t_deque *dque)
{
	while (dque->use_size > 0)
		dque->pop_front(dque);
}
