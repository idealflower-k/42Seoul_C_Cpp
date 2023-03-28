/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:39:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/28 19:45:21 by sanghwal         ###   ########seoul.kr  */
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
pthread_t		*get_philos(void);

#endif