#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"

uint64_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + tv.tv_usec);
}

uint64_t	get_elapsed_time(uint64_t start_time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000000) + tv.tv_usec) - start_time);
}

void	philo_usleep(uint64_t microsec)
{
	const uint64_t	end_time = get_current_time() + microsec;

	usleep(microsec * 0.9);
	while (1)
	{
		usleep(42);
		if (get_current_time() >= end_time)
			return ;
	}
}
