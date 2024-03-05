#include "philosophers.h"
#include "defines.h"
#include "philo_time.h"
#include "utils.h"

t_bool	save_state_message(t_philo *philo, char *state)
{
	t_message	*message;
	t_deque		*deque;

	deque = philo->info.deque;
	message = ft_calloc(1, sizeof(t_message));
	if (!message)
		return (FT_FALSE);
	message->elapsed_time = get_elapsed_time(philo->start_time) / 1000;
	message->id = philo->id;
	message->state = state;
	if (pthread_mutex_lock(philo->info.que_lock))
		return (FT_FALSE);
	deque->push_rear(deque, message);
	if (pthread_mutex_unlock(philo->info.que_lock))
		return (FT_FALSE);
	return (FT_TRUE);
}
