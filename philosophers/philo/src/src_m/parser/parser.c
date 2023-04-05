/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:49:51 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/05 15:43:06 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "utils.h"
#include "meta.h"

t_bool	set_number_of_philosophers(t_arg **args, char *av)
{
	int			num;
	uint64_t	unum;

	if (!ft_atouint64(av, &unum))
	{
		free(*args);
		return (FT_FALSE);
	}
	num = (int)unum;
	if (num < 1)
	{
		free(*args);
		ft_print_err("number of philosophers error\n");
		return (FT_FALSE);
	}
	(*args)->num_philo = num;
	return (FT_TRUE);
}

t_bool	set_times(t_arg **args, char **av)
{
	uint64_t	ft_time;
	int			i;
	int			idx;

	idx = 2;
	i = -1;
	ft_time = 0;
	while (++i < 3)
	{
		if (!ft_atouint64(av[idx++], &ft_time))
		{
			free(*args);
			ft_print_err("invalid time error\n");
			return (FT_FALSE);
		}
		if (i == 0)
			(*args)->t_die = ft_time;
		else if (i == 1)
			(*args)->t_eat = ft_time;
		else
			(*args)->t_sleep = ft_time;
		ft_time = 0;
	}
	return (FT_TRUE);
}

t_bool	set_must_eat(t_arg **args, char *av)
{
	int			num;
	uint64_t	unum;

	if (!ft_atouint64(av, &unum))
	{
		free(*args);
		return (FT_FALSE);
	}
	num = (int)unum;
	if (num < 0)
	{
		free(*args);
		ft_print_err("negative must_eat\n");
		return (FT_FALSE);
	}
	(*args)->must_eat = num;
	return (FT_TRUE);
}
