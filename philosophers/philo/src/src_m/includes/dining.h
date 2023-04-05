/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:00:20 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/05 17:40:31 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINING_H
# define DINING_H

t_bool	set_dining(t_info *info);

/* monitoring */

void	monitoring(void);
t_bool	display_philo_state(void);
t_bool	check_philo(void);
void	terminate_true(void);
t_bool	join_threads(void);

#endif