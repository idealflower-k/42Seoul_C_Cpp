#include "philosophers.h"
#include "defines.h"
#include "parser.h"
#include "philo_time.h"
#include "deque.h"
#include "utils.h"
#include "meta.h"

static t_bool	set_args(t_meta **meta, int ac, char **av)
{
	(*meta)->args = NULL;
	(*meta)->args = ft_calloc(1, sizeof(t_arg));
	if ((*meta)->args == NULL)
		return (FT_FALSE);
	if (!set_number_of_philosophers(&((*meta)->args), av[1]) \
		|| !set_times(&((*meta)->args), av))
		return (FT_FALSE);
	if (ac == 6)
	{
		if (!set_must_eat(&((*meta)->args), av[5]))
			return (FT_FALSE);
	}
	else
		(*meta)->args->must_eat = -1;
	return (FT_TRUE);
}

static t_bool	set_data(t_meta **meta, t_arg *arg)
{
	if ((*meta)->error != NOTHING)
		return (FT_FALSE);
	(*meta)->forks \
		= ft_calloc(arg->num_philo, sizeof(pthread_mutex_t));
	(*meta)->philos = ft_calloc(arg->num_philo, sizeof(t_philo));
	(*meta)->deque = deque_init(arg->num_philo * 5);
	if ((*meta)->forks == NULL \
		|| (*meta)->philos == NULL \
		|| (*meta)->deque == NULL)
	{
		ft_print_err("make_data fail\n");
		free_meta_data();
		return (FT_FALSE);
	}
	(*meta)->threads = NULL;
	(*meta)->start_time = get_current_time();
	return (FT_TRUE);
}

t_meta	*singleton(int ac, char **av)
{
	static t_meta	*meta;

	if (meta != NULL)
		return (meta);
	meta = ft_calloc(1, sizeof(t_meta));
	if (meta == NULL)
		return (NULL);
	if (pthread_mutex_init(&meta->start, NULL))
	{
		free(meta);
		return (NULL);
	}
	if (pthread_mutex_init(&meta->que_lock, NULL))
	{
		pthread_mutex_destroy(&meta->start);
		free(meta);
		return (NULL);
	}
	if (!set_args(&meta, ac, av) || !set_data(&meta, meta->args))
	{
		printf("wrong arguments\n");
		free(meta);
		return (NULL);
	}
	return (meta);
}
