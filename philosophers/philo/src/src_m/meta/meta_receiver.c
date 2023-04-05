/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_receiver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:29:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/05 15:42:10 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "meta.h"

void	*meta_receiver(t_meta_flag flag, int ac, char **av)
{
	t_meta	*meta;

	meta = singleton(ac, av);
	if (flag == META)
		return (meta);
	if (flag == META_ARG)
		return (meta->args);
	if (flag == META_FORKS)
		return (meta->forks);
	if (flag == META_PHILOS)
		return (meta->philos);
	return (NULL);
}
