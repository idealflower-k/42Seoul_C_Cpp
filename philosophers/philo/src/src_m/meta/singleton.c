/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:53:19 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/30 15:26:25 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "parser.h"
#include "philo_time.h"

t_meta	*singleton(int ac, char **av)
{
	static t_meta	*meta;

	if (meta != NULL)
		return (meta);
	meta = ft_calloc(1, sizeof(t_meta));
	if (pthread_mutex_init(&meta->start, NULL))
	{
		meta->error = ERR_MUTEX_INIT;
		return (meta);
	}
	meta->args = ft_calloc(1, sizeof(t_arg));
	set_number_of_philosophers(&(meta->args), av[1]);
	set_times(&(meta->args), av);
	if (ac == 6)
		set_must_eat(&(meta->args), av[5]);
	meta->philos = ft_calloc(meta->args->num_philo, sizeof(t_philo));
	meta->forks = ft_calloc(meta->args->num_philo, sizeof(pthread_mutex_t));
	meta->start_time = get_current_time();
	meta->error = NOTHING;
	return (meta);
}
