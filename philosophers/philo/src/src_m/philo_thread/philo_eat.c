/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:04:50 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/04 19:13:04 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "philo_thread.h"
#include "utils.h"
#include "deque.h"

t_bool	take_left_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->fork[L]))
		return (FT_FALSE);
	return (FT_TRUE);
}

t_bool	take_right_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->fork[R]))
	{
		pthread_mutex_unlock(&philo->fork[L]);
		return (FT_FALSE);
	}
	return (FT_TRUE);
}

static t_bool	set_last_eat(t_philo *philo)
{
	struct timeval	tv;

	if (pthread_mutex_lock(&philo->philo_lock))
		return (FT_FALSE);
	gettimeofday(&tv, NULL);
	philo->last_eat = ((tv.tv_sec * 1000000) + tv.tv_usec);
	philo->eat_cnt++;
	if (pthread_mutex_unlock(&philo->philo_lock))
		return (FT_FALSE);
	return (FT_TRUE);
}

t_bool	save_state_message(t_philo *philo, char *state)
{
	t_message	*message;
	t_deque		*deque;

	deque = philo->info.deque;
	message = ft_calloc(1, sizeof(t_messag));
	message->elapsed_time = get_elapsed_time(philo->info.start_time) / 1000;
	message->id = philo->id;
	message->state = state;
	if (pthread_mutex_lock(&philo->info.que_lock))
		return (FT_FALSE);
	deque->push_rear(deque, message);
	if (pthread_mutex_unlock(&philo->info.que_lock))
		return (FT_FALSE);
	return (FT_TRUE);
}

t_bool	philo_eat(t_philo *philo)
{
	if (take_left_fork(philo))
	{
		if (!take_right_fork(philo))
			return (FT_FALSE);
	}
	else
		return (FT_FALSE);
	if (!set_last_eat(philo))
		// 에러처리
	save_state_message(philo, EATING);
	philo_usleep(philo->info.t_eat * 1000);
	pthread_mutex_unlock(&philo->fork[L]);
	pthread_mutex_unlock(&philo->fork[R]);
	return (FT_TRUE);
}
