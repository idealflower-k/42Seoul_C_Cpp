/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:00:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/25 16:01:38 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_arg	t_arg;

struct s_arg
{
	int			num_philo;
	uint64_t	t_die;
	uint64_t	t_eat;
	uint64_t	t_sleep;
	int			must_eat;
};

#endif