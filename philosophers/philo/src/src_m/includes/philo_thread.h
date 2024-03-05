#ifndef PHILO_THREAD_H
# define PHILO_THREAD_H

t_bool	init_forks(void);
t_bool	init_philo(t_info *info);
t_bool	init_philo_data(t_philo *philo, t_info *info, int id);
void	init_info(t_info *info);
t_bool	create_thread(pthread_t *threads);


void	*start_routine(void *arg);


t_bool	philo_eat(t_philo *philo);


t_bool	philo_sleep(t_philo *philo);


t_bool	philo_think(t_philo *philo);


t_bool	save_state_message(t_philo *philo, char *state);

#endif