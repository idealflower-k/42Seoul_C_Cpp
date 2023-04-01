/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:34:44 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/01 20:57:46 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "meta.h"
#include "deque.h"

void	detach_threads(pthread_t *threads, int num)
{
	const int	cnt = get_args()->num_philo;
	int			i;

	i = 0;
	while (i < cnt)
	{
		if (pthread_detach(threads[i]))
			return ;
		i++;
	}
}

void	destory_forks(int num)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = get_forks();
	i = -1;
	while (++i < num)
		pthread_mutex_destroy(&forks[i]);
}

void	destory_philos(int num)
{
	pthread_mutex_t	*philos;
	int				i;

	philos = get_philos();
	i = -1;
	while (++i < num)
		pthread_mutex_destroy(&philos[i]);
}

static void	free_meta_data(void)
{
	t_meta	*meta;

	meta = get_meta(0, NULL);
	free(meta->args);
	free(meta->forks);
	free(meta->philos);
	dq_free(meta->deque);
}

void	free_all(void)
{
	t_meta	*meta;

	meta = get_meta(0, NULL);
	pthread_mutex_destroy(&meta->start);
	pthread_mutex_destroy(&meta->que_lock);
	free_meta_data();
}
