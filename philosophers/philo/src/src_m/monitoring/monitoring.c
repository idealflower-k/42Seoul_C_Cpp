/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:09:03 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/07 14:58:43 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "deque.h"
#include "meta.h"
#include "monitoring.h"
#include "utils.h"

t_bool	check_philo(t_arg *arg)
{
	uint64_t	curr_time;
	t_philo		*philos;
	int			i;
	int			must_cnt;

	philos = get_philos();
	i = -1;
	must_cnt = 0;
	while (++i < arg->num_philo)
	{
		if (pthread_mutex_lock(&philos[i].philo_lock))
			return (FT_FALSE);
		curr_time = get_current_time();
		if (!check_die(curr_time, &philos[i]))
			return (FT_FALSE);
		if (!check_must_eat(&philos[i], &must_cnt))
			return (FT_FALSE);
		if (pthread_mutex_unlock(&philos[i].philo_lock))
			return (FT_FALSE);
	}
	return (FT_TRUE);
}

t_bool	display_philo_state(void)
{
	t_meta		*meta;
	t_deque		*deque;
	t_message	*message;

	meta = get_meta(0, NULL);
	deque = meta->deque;
	while (check_philo(meta->args))
	{
		if (pthread_mutex_lock(&meta->que_lock))
			return (FT_FALSE);
		if (deque->use_size > 0)
		{
			message = deque->pop_front(deque);
			print_message(message->elapsed_time, message->id, message->state);
			free(message);
		}
		if (pthread_mutex_unlock(&meta->que_lock))
			return (FT_FALSE);
	}
	return (FT_FALSE);
}

t_bool	join_threads(void)
{
	t_meta		*meta;
	t_arg		*arg;
	pthread_t	*threads;
	int			i;

	meta = get_meta(0, NULL);
	arg = meta->args;
	threads = meta->threads;
	i = -1;
	while (++i < arg->num_philo)
		pthread_join(threads[i], NULL);
	return (FT_TRUE);
}

void	monitoring(void)
{
	t_meta	*meta;

	meta = get_meta(0, NULL);
	display_philo_state();
	if (!terminate_true())
		detach_threads(meta->threads, meta->args->num_philo);
	else
		join_threads();
}
