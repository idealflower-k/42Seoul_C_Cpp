/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:35:43 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/30 13:56:26 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"

void	time_test(void)
{
	uint64_t	current_time;
	uint64_t	elapsed_time;

	current_time = get_current_time();
	elapsed_time = get_elapsed_time(100);
	printf("current_time : %llu\n", current_time);
	printf("elapsed_time : %llu\n", elapsed_time);
}
