/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:00:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/29 22:04:11 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_arg		t_arg;
typedef struct s_meta		t_meta;
typedef struct s_info		t_info;
typedef struct s_philo		t_philo;
typedef enum e_meta_flag	t_meta_flag;

# define L 0
# define R 1

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
	t_philo			*philos;
	int				err;
	pthread_mutex_t	start;
	uint64_t		start_time;
};

enum e_meta_flag
{
	META,
	META_ARG,
	META_FORKS,
	META_PHILOS
};

struct s_info
{
	pthread_mutex_t	*start;
	uint64_t		*start_time;
	uint64_t		t_die;
	uint64_t		t_eat;
	uint64_t		t_sleep;
	int				must_eat;
};

struct s_philo
{
	int				id;
	int				eat_cnt;
	uint64_t		last_eat;
	t_bool			terminate;
	t_info			info;
	pthread_mutex_t	fork[2];
	pthread_mutex_t	philo_lock;
};

#endif