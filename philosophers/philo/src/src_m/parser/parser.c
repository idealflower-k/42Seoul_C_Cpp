/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:49:51 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/25 15:18:04 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	parser_args(t_arg **args, int ac, char **av)
{
	*args = ft_calloc(1, sizeof(t_arg));
	set_number_of_philosophers(args, &av[1]);
	set_times(args, &av[2]);
	if (ac == 6)
		set_must_eat(args, &av[5]);
}

void	set_number_of_philosophers(t_arg **args, char *av)
{
	int	num;

	num = ft_atoi(av);
	if (num < 1)
	{
		free(*args);
		ft_print_exit("few philosophers\n", 1);
	}
	(*args)->num_philo = num;
}

void	set_times(t_arg **args, char *av)
{
	uint64_t	ft_time;
	int			i;

	i = 0;
	while (i < 3)
	{
		ft_time = ft_atoi(av);
		if (ft_time < 0)
		{
			free(*args);
			ft_print_exit("negative time\n", 1);
		}
		if (i == 0)
			(*args)->t_die = ft_time;
		else if (i == 1)
			(*args)->t_eat = ft_time;
		else
			(*args)->t_sleep = ft_time;
		ft_time = 0;
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
