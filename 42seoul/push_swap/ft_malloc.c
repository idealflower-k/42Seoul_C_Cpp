/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:05:38 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/01 20:06:46 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_malloc(size_t size_of)
{
	void	*p;

	p = malloc(size_of);
	if (p == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(p, 0, size_of);
	return (p);
}
