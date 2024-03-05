#ifndef DINING_H
# define DINING_H

t_bool	set_dining(t_info *info);
t_bool	init_philo(t_info *info);
t_bool	init_philo_data(t_philo *philo, t_info *info, int id);
void	init_info(t_info *info);
t_bool	init_forks(void);

#endif