/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:04:50 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/02 17:48:23 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "philo_thread.h"

static t_bool	take_left_fork(t_philo *philo)
{

}

static t_bool	take_right_fork(t_philo *philo)
{

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
	return (FT_TRUE);
}
