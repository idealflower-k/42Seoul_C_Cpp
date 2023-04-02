/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:51:40 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/02 20:02:12 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"

uint64_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + tv.tv_usec);
}

uint64_t	get_elapsed_time(uint64_t start_time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000000) + tv.tv_usec) - start_time);
}

void	philo_usleep(uint64_t microsec)
{
	const uint64_t	end_time = get_current_time() + microsec;

	usleep(microsec * 0.9);
	while (1)
	{
		usleep(42);
		if (current_time() >= end_time)
			return ;
	}
}
