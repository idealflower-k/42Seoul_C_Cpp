/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_invoker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:14:22 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/28 19:47:51 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "meta.h"

t_meta	*get_meta(int ac, char **av)
{
	return ((t_meta *)meta_receiver(META, ac, av));
}

pthread_mutex_t	*get_forks(void)
{
	return ((pthread_mutex_t *)meta_receiver(META_FORKS, 0, NULL));
}

pthread_t	*get_philos(void)
{
	return ((pthread_t *)meta_receiver(META_PHILOS, 0, NULL));
}
