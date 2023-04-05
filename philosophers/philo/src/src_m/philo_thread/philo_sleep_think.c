/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep_think.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:23:15 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/05 20:59:26 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "philo_thread.h"

t_bool	philo_sleep(t_philo *philo)
{
	if (!save_state_message(philo, SLEEPING))
		return (FT_FALSE);
	philo_usleep(philo->info.t_sleep * 1000);
	return (FT_TRUE);
}

t_bool	philo_think(t_philo *philo)
{
	if (!save_state_message(philo, THINKING))
		return (FT_FALSE);
	return (FT_TRUE);
}
