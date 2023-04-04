/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:12:26 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/04 16:44:14 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "philo_thread.h"

static t_bool	philo_sleep(t_philo *philo)
{

}

static t_bool	philo_think(t_philo *philo)
{

}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (pthread_mutex_lock(philo->info.start))
		return (FT_FALSE);
	if (pthread_mutex_unlock(philo->info.start))
		return (FT_FALSE);
	while (!check_terminate(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return ;
}
