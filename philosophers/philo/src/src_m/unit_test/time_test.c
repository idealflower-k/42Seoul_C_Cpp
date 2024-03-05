#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"

void	time_test(void)
{
	uint64_t	current_time;
	uint64_t	elapsed_time;

	current_time = get_current_time();
	elapsed_time = get_elapsed_time(100);
	printf("current_time : %llu\n", current_time);
	printf("elapsed_time : %llu\n", elapsed_time);
}
