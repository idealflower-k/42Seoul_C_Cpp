/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:53:11 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/05 15:06:23 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREAD_H
# define PHILO_THREAD_H

t_bool	init_forks(void);
t_bool	init_philo(t_info *info);
t_bool	init_philo_data(t_philo *philo, t_info *info, int id);
void	init_info(t_info *info);
t_bool	create_thread(pthread_t *threads);

/* routine */
void	*start_routine(void *arg);

/* eat */
t_bool	philo_eat(t_philo *philo);

/* sleep */
t_bool	philo_sleep(t_philo *philo);

/* think */
t_bool	philo_think(t_philo *philo);

/* utils */
t_bool	save_state_message(t_philo *philo, char *state);

#endif