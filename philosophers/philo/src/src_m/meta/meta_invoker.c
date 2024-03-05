#include "philosophers.h"
#include "defines.h"
#include "meta.h"

t_meta	*get_meta(int ac, char **av)
{
	return ((t_meta *)meta_receiver(META, ac, av));
}

pthread_mutex_t	*get_forks(void)
{
	return ((pthread_mutex_t *)meta_receiver(META_FORKS, 0, NULL));
}

t_philo	*get_philos(void)
{
	return ((t_philo *)meta_receiver(META_PHILOS, 0, NULL));
}

t_arg	*get_args(void)
{
	return ((t_arg *)meta_receiver(META_ARG, 0, NULL));
}

int	get_err(void)
{
	return ((int)meta_receiver(META_ERR, 0, NULL));
}
