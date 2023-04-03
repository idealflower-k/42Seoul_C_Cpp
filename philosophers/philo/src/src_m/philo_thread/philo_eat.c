/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:04:50 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/03 11:39:11 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "philo_thread.h"

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
		pthread_mutex_unlock(&philo->fork[R]);
		return (FT_FALSE);
	}
	return (FT_TRUE);
}

static void	set_last_eat(t_philo *philo)
{
	struct timeval	tv;

	pthread_mutex_lock(&philo->philo_lock);
	gettimeofday(&tv, NULL);
	philo->last_eat = ((tv.tv_sec * 1000000) + tv.tv_usec);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->philo_lock);
}

static void	write_eat_state(t_philo *philo)
{
	uint64_t	elapsed_time;
	char		*eat_state_line;

	elapsed_time = get_elapsed_time(philo->info.start_time) / 1000;
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
	set_last_eat(philo);
	write_eat_state(philo);
	philo_usleep(philo->info.t_eat * 1000);
	pthread_mutex_unlock(&philo->fork[L]);
	pthread_mutex_unlock(&philo->fork[R]);
	return (FT_TRUE);
}
