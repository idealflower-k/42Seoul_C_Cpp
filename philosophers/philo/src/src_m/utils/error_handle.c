/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:34:44 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/30 15:54:36 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "meta.h"

void	detach_threads(pthread_t *threads)
{
	const int	cnt = get_args()->num_philo;
	int			i;

	i = 0;
	while (i < cnt)
	{
		pthread_detach(threads[i]);
		i++;
	}
}

void	destory_forks(void)
{
	pthread_mutex_t	*forks;
	int				cnt;
	int				i;

	forks = get_forks();
	cnt = get_args()->num_philo;
	i = 0;
	while (i < cnt)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	error_handler(int err_num)
{
	t_meta	*meta;

	meta = get_meta(0, NULL);
	free(meta->philos);
	free(meta->args->num_philo);
	free(meta->args);
	pthread_mutex_destroy(&meta->start);
	destory_forks();
}
