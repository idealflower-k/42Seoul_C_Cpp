#ifndef META_H
# define META_H



t_meta			*singleton(int ac, char **av);
void			*meta_receiver(t_meta_flag flag, int ac, char **av);



t_meta			*get_meta(int ac, char **av);
pthread_mutex_t	*get_forks(void);
t_philo			*get_philos(void);
t_arg			*get_args(void);
void			set_err(t_err err);

#endif