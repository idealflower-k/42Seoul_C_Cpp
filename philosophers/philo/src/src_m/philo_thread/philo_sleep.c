/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:23:15 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/04 16:25:56 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "philo_thread.h"
#include "utils.h"
#include "deque.h"

void	philo_sleep(t_philo *philo)
{
	save_state_message(philo, SLEEPING);
	philo_usleep(philo->info.t_sleep * 1000);
}
