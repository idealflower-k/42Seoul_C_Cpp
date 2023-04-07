/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:26:32 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/07 15:37:38 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "deque.h"
#include "meta.h"
#include "monitoring.h"

t_bool	check_die(uint64_t curr_time, t_philo *philo)
{
	const uint64_t	start_time = philo->start_time;
	const uint64_t	elapsed_time = get_elapsed_time(start_time) / 1000;
	const int		id = philo->id;

	if (((curr_time - philo->last_eat) / 1000) >= philo->info.t_die)
	{
		print_message(elapsed_time, id, DIE);
		pthread_mutex_unlock(&philo->philo_lock);
		return (FT_FALSE);
	}
	return (FT_TRUE);
}

t_bool	check_must_eat(t_philo *philo, int *must_cnt)
{
	const t_arg		*arg = get_args();

	if (arg->must_eat == -1)
		return (FT_TRUE);
	if (philo->eat_cnt >= philo->info.must_eat)
		(*must_cnt)++;
	if (*must_cnt == arg->num_philo)
	{
		if (!print_all_message())
			return (FT_FALSE);
		print_message(0, 0, MUST_EAT);
		pthread_mutex_unlock(&philo->philo_lock);
		return (FT_FALSE);
	}
	return (FT_TRUE);
}

t_bool	print_all_message(void)
{
	t_meta		*meta;
	t_deque		*deque;
	t_message	*message;

	meta = get_meta(0, NULL);
	deque = meta->deque;
	philo_usleep(42);
	if (pthread_mutex_lock(&meta->que_lock))
		return (FT_FALSE);
	while (deque->use_size > 0)
	{
		message = deque->pop_front(deque);
		print_message(message->elapsed_time, message->id, message->state);
		free(message);
	}
	if (pthread_mutex_unlock(&meta->que_lock))
		return (FT_FALSE);
	return (FT_TRUE);
}

void	print_message(uint64_t elapsed_time, int id, char *state)
{
	if (elapsed_time == 0 && id == 0)
		printf("%s", state);
	else
		printf("%llu %d %s", \
				elapsed_time, id, state);
}

t_bool	terminate_true(void)
{
	t_philo	*philos;
	t_arg	*arg;
	int		i;
	t_bool	bool;

	philos = get_philos();
	arg = get_args();
	bool = FT_TRUE;
	i = -1;
	while (++i < arg->num_philo)
	{
		if (pthread_mutex_lock(&philos[i].philo_lock))
			bool = FT_FALSE;
		philos[i].terminate = FT_TRUE;
		if (pthread_mutex_unlock(&philos[i].philo_lock))
			bool = FT_FALSE;
	}
	if (bool == FT_FALSE)
		return (FT_FALSE);
	return (FT_TRUE);
}
