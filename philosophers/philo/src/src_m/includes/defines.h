/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:00:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/06 19:29:46 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef enum e_meta_flag	t_meta_flag;
typedef enum e_state		t_state;
typedef enum e_err			t_err;
typedef enum e_bool			t_bool;

typedef struct s_arg		t_arg;
typedef struct s_meta		t_meta;
typedef struct s_info		t_info;
typedef struct s_philo		t_philo;
typedef struct s_deque		t_deque;
typedef struct s_message	t_message;

# define L 0
# define R 1
# define MUTEX_INIT "mutex_init failed\n"
# define PTHREAD_CREATE "pthread_create failed\n"

# define TAKE_FORK "has taken a fork\n"
# define EATING "is eating\n"
# define SLEEPING "is sleeping\n"
# define THINKING "is thinking\n"
# define DIE "died\n"
# define MUST_EAT "Everyone ate as much as must_eat\n"

enum e_bool
{
	FT_FALSE,
	FT_TRUE
};
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
	uint64_t		start_time;
	pthread_mutex_t	start;
	t_deque			*deque;
	pthread_mutex_t	que_lock;
	pthread_t		*threads;
	int				error;
};

enum e_meta_flag
{
	META,
	META_ARG,
	META_FORKS,
	META_PHILOS,
	MALLOC_ERR,
	META_ERR
};

struct s_info
{
	pthread_mutex_t	*start;
	uint64_t		*start_time;
	pthread_mutex_t	*que_lock;
	t_deque			*deque;
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
	pthread_mutex_t	*fork[2];
	pthread_mutex_t	philo_lock;
};

struct s_message
{
	int			id;
	uint64_t	elapsed_time;
	char		*state;
};

struct s_deque
{
	size_t	capacity;
	size_t	front;
	size_t	rear;
	size_t	use_size;
	void	**nodes;
	void	(*push_front)(t_deque *, void *);
	void	(*push_rear)(t_deque *, void *);
	void	*(*pop_front)(t_deque *);
	void	*(*pop_rear)(t_deque *);
	void	*(*peek_front)(const t_deque *);
	void	*(*peek_rear)(const t_deque *);
};

enum e_err
{
	NOTHING,
	ERR_MUTEX_INIT,
	ERR_PTHREAD_CREATE
};

#endif