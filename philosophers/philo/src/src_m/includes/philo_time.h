#ifndef PHILO_TIME_H
# define PHILO_TIME_H

uint64_t	get_current_time(void);
uint64_t	get_elapsed_time(uint64_t start_time);
void		philo_usleep(uint64_t microsec);

#endif