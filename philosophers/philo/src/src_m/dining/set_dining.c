#include "philosophers.h"
#include "defines.h"
#include "philo_thread.h"
#include "philo_time.h"
#include "utils.h"
#include "deque.h"
#include "meta.h"

t_bool	set_dining(t_info *info)
{
	t_meta		*meta;
	pthread_t	*threads;

	meta = get_meta(0, NULL);
	init_info(info);
	if (!init_forks() || !init_philo(info))
		return (FT_FALSE);
	threads = ft_calloc(meta->args->num_philo, sizeof(pthread_t));
	if (!threads)
		return (FT_FALSE);
	meta->threads = threads;
	if (pthread_mutex_lock(&meta->start))
		return (FT_FALSE);
	if (!create_thread(threads))
	{
		pthread_mutex_unlock(&meta->start);
		return (FT_FALSE);
	}
	meta->start_time = get_current_time();
	if (pthread_mutex_unlock(&meta->start))
		return (FT_FALSE);
	philo_usleep(meta->args->t_die);
	return (FT_TRUE);
}
