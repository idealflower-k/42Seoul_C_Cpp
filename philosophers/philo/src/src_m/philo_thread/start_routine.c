#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "philo_thread.h"
#include "philo_time.h"

static t_bool	check_terminate(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->philo_lock))
		return (FT_FALSE);
	if (philo->terminate == FT_TRUE)
	{
		pthread_mutex_unlock(&philo->philo_lock);
		return (FT_FALSE);
	}
	if (pthread_mutex_unlock(&philo->philo_lock))
		return (FT_FALSE);
	return (FT_TRUE);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (pthread_mutex_lock(&philo->philo_lock))
		return (NULL);
	philo->last_eat = philo->start_time;
	if (pthread_mutex_unlock(&philo->philo_lock))
		return (NULL);
	if (pthread_mutex_lock(philo->info.start))
		return (NULL);
	if (pthread_mutex_unlock(philo->info.start))
		return (NULL);
	if (philo->id % 2 == 1)
		philo_usleep(philo->info.t_eat);
	while (check_terminate(philo))
	{
		if (!philo_eat(philo))
			return (NULL);
		if (!philo_sleep(philo))
			return (NULL);
		if (!philo_think(philo))
			return (NULL);
	}
	return (NULL);
}
