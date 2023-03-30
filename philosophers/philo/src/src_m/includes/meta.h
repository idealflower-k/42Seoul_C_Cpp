/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:39:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/30 13:41:52 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_H
# define META_H

/* meta_receiver.c */

t_meta			*singleton(int ac, char **av);
void			*meta_receiver(t_meta_flag flag, int ac, char **av);

/* meta_receiver.c */

t_meta			*get_meta(int ac, char **av);
pthread_mutex_t	*get_forks(void);
t_philo			*get_philos(void);
t_arg			*get_args(void);

#endif