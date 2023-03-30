/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:49:51 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/30 13:53:48 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"

void	set_number_of_philosophers(t_arg **args, char *av)
{
	int	num;

	num = ft_atoi(av);
	if (num < 1)
	{
		free(*args);
		ft_print_exit("number of philosophers error\n", 1);
	}
	(*args)->num_philo = num;
}

void	set_times(t_arg **args, char **av)
{
	uint64_t	ft_time;
	int			i;
	int			idx;

	idx = 2;
	i = 0;
	ft_time = 0;
	while (i < 3)
	{
		if (!ft_atouint64(av[idx], &ft_time))
		{
			free(*args);
			ft_print_exit("invalid time error\n", 1);
		}
		if (i == 0)
			(*args)->t_die = ft_time;
		else if (i == 1)
			(*args)->t_eat = ft_time;
		else
			(*args)->t_sleep = ft_time;
		ft_time = 0;
		i++;
		idx++;
	}
}

void	set_must_eat(t_arg **args, char *av)
{
	int	num;

	num = ft_atoi(av);
	if (num < 0)
	{
		free(*args);
		ft_print_exit("negative must_eat\n", 1);
	}
	(*args)->must_eat = num;
}
