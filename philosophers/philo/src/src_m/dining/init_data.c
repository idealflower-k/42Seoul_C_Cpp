/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:34:02 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/07 14:29:52 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "meta.h"
#include "philo_thread.h"
#include "utils.h"

t_bool	init_forks(void)
{
	t_meta	*meta;
	int		i;

	meta = get_meta(0, NULL);
	i = -1;
	while (++i < meta->args->num_philo)
	{
		if (pthread_mutex_init(&meta->forks[i], NULL))
		{
			meta->error = ERR_MUTEX_INIT;
			destory_forks(i);
			return (FT_FALSE);
		}
	}
	return (FT_TRUE);
}

void	init_info(t_info *info)
{
	t_meta	*meta;
	t_arg	*args;

	meta = get_meta(0, NULL);
	args = meta->args;
	(*info).t_die = args->t_die;
	(*info).t_eat = args->t_eat;
	(*info).t_sleep = args->t_sleep;
	(*info).must_eat = args->must_eat;
	(*info).start = &meta->start;
	(*info).que_lock = &meta->que_lock;
	(*info).deque = meta->deque;
}

t_bool	init_philo_data(t_philo *philo, t_info *info, int id)
{
	const t_meta	*meta = get_meta(0, NULL);
	const t_arg		*args = meta->args;

	philo->id = id + 1;
	philo->eat_cnt = 0;
	philo->last_eat = 0;
	philo->terminate = FT_FALSE;
	philo->info = *info;
	philo->start_time = meta->start_time;
	philo->fork[L] = &meta->forks[philo->id - 1];
	if (philo->id == 1)
		philo->fork[R] = &meta->forks[args->num_philo - 1];
	else
		philo->fork[R] = &meta->forks[philo->id - 2];
	if (pthread_mutex_init(&philo->philo_lock, NULL))
		return (FT_FALSE);
	return (FT_TRUE);
}

t_bool	init_philo(t_info *info)
{
	const t_arg	*args = get_args();
	t_philo		*philos;
	int			i;

	philos = get_philos();
	i = 0;
	while (i < args->num_philo)
	{
		if (!init_philo_data(&philos[i], info, i))
		{
			destory_forks(args->num_philo);
			destory_philos(i);
			return (FT_FALSE);
		}
		i++;
	}
	return (FT_TRUE);
}
