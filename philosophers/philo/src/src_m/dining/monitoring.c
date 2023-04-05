/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:09:03 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/05 20:59:02 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "deque.h"
#include "meta.h"

t_bool	check_philo(void)
{
	t_philo	*philos;
	t_arg	*arg;
	int		i;

	philos = get_philos();
	arg = get_args();
	i = -1;
	while (++i < arg->num_philo)
	{
		pthread_mutex_lock(&philos[i].philo_lock);
		if (philos[i].last_eat != 0 && \
			get_current_time() - philos[i].last_eat >= arg->t_die * 1000000)
		{
			pthread_mutex_unlock(&philos[i].philo_lock);
			return (FT_FALSE);
		}
		pthread_mutex_unlock(&philos[i].philo_lock);
	}
	return (FT_TRUE);
}

void	terminate_true(void)
{
	t_philo	*philos;
	t_arg	*arg;
	int		i;

	philos = get_philos();
	arg = get_args();
	i = -1;
	while (++i < arg->num_philo)
	{
		pthread_mutex_lock(&philos[i].philo_lock);
		philos[i].terminate = FT_TRUE;
		pthread_mutex_unlock(&philos[i].philo_lock);
	}
}

t_bool	display_philo_state(void)
{
	t_meta		*meta;
	t_deque		*deque;
	t_message	*message;

	meta = get_meta(0, NULL);
	deque = meta->deque;
	while (check_philo())
	{
		pthread_mutex_lock(&meta->que_lock);
		if (deque->use_size > 0)
		{
			message = deque->pop_front(deque);
			printf("%llu %d %s", \
				message->elapsed_time, message->id, message->state);
			free(message);
		}
		pthread_mutex_unlock(&meta->que_lock);
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
	display_philo_state();
	terminate_true();
	join_threads();
}
