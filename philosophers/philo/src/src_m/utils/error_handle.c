#include "philosophers.h"
#include "defines.h"
#include "meta.h"
#include "deque.h"

void	detach_threads(pthread_t *threads, int num)
{
	int			i;

	i = 0;
	while (i < num)
	{
		if (pthread_detach(threads[i]))
			return ;
		i++;
	}
}

void	destory_forks(int num)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = get_forks();
	i = -1;
	while (++i < num)
		pthread_mutex_destroy(&forks[i]);
}

void	destory_philos(int num)
{
	t_philo	*philos;
	int		i;

	philos = get_philos();
	i = -1;
	while (++i < num)
		pthread_mutex_destroy(&philos[i].philo_lock);
}

void	free_meta_data(void)
{
	t_meta	*meta;

	meta = get_meta(0, NULL);
	free(meta->args);
	free(meta->forks);
	free(meta->philos);
	free(meta->threads);
	dq_free(meta->deque);
}

void	free_all(void)
{
	t_meta	*meta;

	meta = get_meta(0, NULL);
	pthread_mutex_destroy(&meta->start);
	pthread_mutex_destroy(&meta->que_lock);
	free_meta_data();
}
