/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:04:50 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/02 20:03:51 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "philo_thread.h"

t_bool	take_left_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->fork[L]))
		return (FT_FALSE);
	return (FT_TRUE);
}

t_bool	take_right_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->fork[R]))
	{
		pthread_mutex_unlock(philo->fork[R]);
		return (FT_FALSE);
	}
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
	// 라스트밀 시간 조정
	// 출력 처리
	// 먹은 카운트 업
	philo_usleep(philo->info.t_eat * 1000);
	pthread_mutex_unlock(philo->fork[L]);
	pthread_mutex_unlock(philo->fork[R]);
	return (FT_TRUE);
}
