/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:48:31 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/25 16:30:14 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "parser.h"

void	parser_test(t_arg **args, int ac, char **av)
{
	parser_args(args, ac, av);
	printf("------ PARSER_TEST ------\n");
	printf("Number of philos : %d\n", (*args)->num_philo);
	printf("Time to DIE : %llu\n", (*args)->t_die);
	printf("Time to EAT : %llu\n", (*args)->t_eat);
	printf("Time to SLEEP : %llu\n", (*args)->t_sleep);
	if (ac == 6)
		printf("Must have to eat : %d\n", (*args)->must_eat);
	printf("------ END TEST ------\n");
	free(*args);
}
