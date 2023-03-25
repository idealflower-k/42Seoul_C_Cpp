/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:49:51 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/25 16:32:10 by sanghwal         ###   ########seoul.kr  */
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
	while (i < 3)
	{
		ft_time = (uint64_t)ft_atoi(av[idx]);
		if (ft_time < 0 || av[idx][0] == '-')
		{
			free(*args);
			ft_print_exit("time error\n", 1);
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

void	parser_args(t_arg **args, int ac, char **av)
{
	*args = ft_calloc(1, sizeof(t_arg));
	set_number_of_philosophers(args, av[1]);
	set_times(args, av);
	if (ac == 6)
		set_must_eat(args, av[5]);
}
