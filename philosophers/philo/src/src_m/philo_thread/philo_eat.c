#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "philo_thread.h"
#include "utils.h"
#include "deque.h"

static t_bool	take_left_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->fork[L]))
		return (FT_FALSE);
	save_state_message(philo, TAKE_FORK);
	return (FT_TRUE);
}

static t_bool	take_right_fork(t_philo *philo)
{
	if (philo->fork[L] == philo->fork[R])
	{
		pthread_mutex_unlock(philo->fork[L]);
		return (FT_FALSE);
	}
	if (pthread_mutex_lock(philo->fork[R]))
	{
		pthread_mutex_unlock(philo->fork[L]);
		return (FT_FALSE);
	}
	save_state_message(philo, TAKE_FORK);
	return (FT_TRUE);
}

static t_bool	set_last_eat(t_philo *philo)
{
	struct timeval	tv;

	if (pthread_mutex_lock(&philo->philo_lock))
		return (FT_FALSE);
	gettimeofday(&tv, NULL);
	philo->last_eat = ((tv.tv_sec * 1000000) + tv.tv_usec);
	philo->eat_cnt++;
	if (pthread_mutex_unlock(&philo->philo_lock))
		return (FT_FALSE);
	return (FT_TRUE);
}

t_bool	philo_eat(t_philo *philo)
{
	if (take_left_fork(philo))
	{
		if (!take_right_fork(philo))
			return (FT_FALSE);
	}
	else
		return (FT_FALSE);
	if (!set_last_eat(philo))
		return (FT_FALSE);
	if (!save_state_message(philo, EATING))
		return (FT_FALSE);
	philo_usleep(philo->info.t_eat * 1000);
	if (pthread_mutex_unlock(philo->fork[L]) \
		|| pthread_mutex_unlock(philo->fork[R]))
		return (FT_FALSE);
	return (FT_TRUE);
}
