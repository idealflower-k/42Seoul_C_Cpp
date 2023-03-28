/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:53:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/28 19:57:31 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "meta.h"

void	create_philos(void)
{
	t_meta	*meta;
	int		i;

	meta = get_meta(0, NULL);
	i = 0;
	while (i < meta->args->num_philo)
	{
		
	}
}
