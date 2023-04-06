/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:26:32 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/06 20:46:07 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "deque.h"
#include "meta.h"
#include "monitoring.h"

t_bool	check_die(uint64_t curr_time, t_philo *philo)
{
	const uint64_t	start_time = *philo->info.start_time;
	const uint64_t	elapsed_time = get_elapsed_time(start_time) / 1000;
	const int		id = philo->id;

	if (((curr_time - philo->last_eat) / 1000) >= philo->info.t_die)
	{
		printf("die time : %llu\n", ((curr_time - philo->last_eat) / 1000));
		printf("t_die : %llu\n", philo->info.t_die);
		print_message(elapsed_time, id, DIE);
		pthread_mutex_unlock(&philo->philo_lock);
		return (FT_FALSE);
	}
	return (FT_TRUE);
}

t_bool	check_must_eat(t_philo *philo, int *must_cnt)
{
	const t_arg		*arg = get_args();

	if (arg->must_eat == -1)
		return (FT_TRUE);
	if (philo->eat_cnt >= philo->info.must_eat)
		(*must_cnt)++;
	if (*must_cnt == arg->num_philo)
	{
		print_all_message();
		print_message(0, 0, MUST_EAT);
		pthread_mutex_unlock(&philo->philo_lock);
		return (FT_FALSE);
	}
	return (FT_TRUE);
}

void	print_all_message(void)
{
	t_deque		*deque;
	t_message	*message;

	deque = get_meta(0, NULL)->deque;
	while (deque->use_size > 0)
	{
		message = deque->pop_front(deque);
		print_message(message->elapsed_time, message->id, message->state);
		free(message);
	}
}

void	print_message(uint64_t elapsed_time, int id, char *state)
{
	if (elapsed_time == 0 && id == 0)
		printf("%s", state);
	else
		printf("%llu %d %s", \
				elapsed_time, id, state);
}

void	terminate_true(void)
{
	t_philo	*philos;
	t_arg	*arg;
	int		i;

	philos = get_philos();
	arg = get_args();
	i = -1;
	while (++i < arg->num_philo)
	{
		pthread_mutex_lock(&philos[i].philo_lock);
		philos[i].terminate = FT_TRUE;
		pthread_mutex_unlock(&philos[i].philo_lock);
	}
}
