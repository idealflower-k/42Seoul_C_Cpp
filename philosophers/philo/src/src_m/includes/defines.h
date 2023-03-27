/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:00:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/27 18:37:36 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_arg	t_arg;
typedef struct s_meta	t_meta;
typedef struct s_philo	t_philo;

struct s_arg
{
	int			num_philo;
	uint64_t	t_die;
	uint64_t	t_eat;
	uint64_t	t_sleep;
	int			must_eat;
};

struct s_meta
{
	t_arg			*args;
	pthread_mutex_t	*forks;
	t_bool			died;
};


struct s_philo
{
	uint64_t		last_meal;
	pthread_mutex_t	fork[2];
};

#endif