/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:53:19 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/02 19:13:26 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "parser.h"
#include "philo_time.h"
#include "deque.h"
#include "utils.h"
#include "meta.h"

static t_bool	set_args(t_meta **meta, int ac, char **av)
{
	(*meta)->args = NULL;
	if ((*meta)->error != NOTHING)
		return (FT_FALSE);
	(*meta)->args = ft_calloc(1, sizeof(t_arg));
	if ((*meta)->args == NULL)
	{
		set_err(MALLOC_ERR);
		return (FT_FALSE);
	}
	if (!set_number_of_philosophers(&((*meta)->args), av[1]) \
		|| !set_times(&((*meta)->args), av))
	{
		set_err(META_ARG);
		return (FT_FALSE);
	}
	if (ac == 6)
	{
		if (!set_must_eat(&((*meta)->args), av[5]))
		{
			set_err(META_ARG);
			return (FT_FALSE);
		}
	}
	return (FT_TRUE);
}

static t_bool	set_data(t_meta **meta, t_arg *arg)
{
	if ((*meta)->error != NOTHING)
		return (FT_FALSE);
	(*meta)->forks \
		= ft_calloc((*meta)->args->num_philo, sizeof(pthread_mutex_t));
	(*meta)->philos = ft_calloc((*meta)->args->num_philo, sizeof(t_philo));
	(*meta)->deque = deque_init((*meta)->args->num_philo * 4);
	if ((*meta)->forks == NULL \
		|| (*meta)->philos == NULL \
		|| (*meta)->deque == NULL)
	{
		set_err(MALLOC_ERR);
		return (FT_FALSE);
	}
	(*meta)->start_time = get_current_time();
	return (FT_TRUE);
}

t_meta	*singleton(int ac, char **av)
{
	static t_meta	*meta;

	if (meta != NULL)
		return (meta);
	meta = ft_calloc(1, sizeof(t_meta));
	if (meta == NULL)
		return (meta);
	meta->error = NOTHING;
	if (pthread_mutex_init(&meta->start, NULL) \
	|| pthread_mutex_init(&meta->que_lock, NULL))
		set_err(ERR_MUTEX_INIT);
	if (!set_args(&meta, ac, av) || !set_data(&meta, meta->args))
		return (meta);
}
