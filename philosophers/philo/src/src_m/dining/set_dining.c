/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dining.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:01:09 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/01 20:49:04 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_thread.h"
#include "philo_time.h"
#include "utils.h"
#include "deque.h"
#include "meta.h"

t_bool	set_dining(t_info *info)
{
	t_meta		*meta;
	pthread_t	*threads;

	meta = get_meta(0, NULL);
	init_info(info);
	if (!init_forks() || !init_philo(info))
		return (FT_FALSE);
	threads = ft_calloc(meta->args->num_philo, sizeof(pthread_t));
	pthread_mutex_lock(&meta->start);
	if (!create_thread(threads))
	{
		pthread_mutex_unlock(&meta->start);
		return (FT_FALSE);
	}
	meta->start_time = get_current_time();
	pthread_mutex_unlock(&meta->start);
	philo_usleep(meta->args->t_die * 0.5);
}
