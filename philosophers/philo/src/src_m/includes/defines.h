/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:00:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/28 19:54:37 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_arg		t_arg;
typedef struct s_meta		t_meta;
typedef struct s_philo		t_philo;
typedef struct s_request	t_request;
typedef enum e_meta_flag	t_meta_flag;

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
	pthread_t		*philos;
	int				err;
};

enum e_meta_flag
{
	META,
	META_ARG,
	META_FORKS,
	META_PHILOS
};

struct s_request
{
	t_bool	terminate;
};

struct s_philo
{
	uint64_t		last_meal;
	pthread_mutex_t	fork[2];
	t_request		*request;
};

#endif