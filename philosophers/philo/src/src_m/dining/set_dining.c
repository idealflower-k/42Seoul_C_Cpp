/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dining.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:01:09 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/30 15:48:55 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philo_thread.h"
#include "defines.h"
#include "philo_time.h"
#include "utils.h"

t_bool	set_dining(t_info *info)
{
	t_meta		*meta;
	pthread_t	*threads;

	meta = get_meta();
	if (!init_forks())
		return (FT_FALSE);
	init_info(info);
	if (!init_philo(info))
		return (FT_FALSE);
	threads = ft_calloc(meta->args->num_philo, sizeof(pthread_t));
	pthread_mutex_lock(&meta->start);
	if (!create_thread(threads))
	{
		detach_threads(threads);
		pthread_mutex_unlock(&meta->start);
		return (FT_FALSE);
	}
	meta->start_time = get_current_time();
	pthread_mutex_unlock(&meta->start);
	philo_usleep(meta->args->t_die * 0.7);
}
