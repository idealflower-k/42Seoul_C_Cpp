/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:53:11 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/29 22:22:52 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREAD_H
# define PHILO_THREAD_H

void	*start_routine(void *arg);
void	init_philo(t_info *info);
t_bool	init_philo_data(t_philo *philo, t_info *info, int id);
static	t_info	init_info(t_meta *meta, t_info *info);

#endif