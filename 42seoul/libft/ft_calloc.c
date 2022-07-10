/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IdealFlower <IdealFlower@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:02:59 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/09 00:21:58 by IdealFlower      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (size > SIZE_MAX / count)
		return (0);
	temp = malloc(size * count);
	if (temp == 0)
		return (0);
	ft_bzero(temp, (count * size));
	return (temp);
}
