/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:02:59 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/15 10:58:14 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (count && size > SIZE_MAX / count)
		return ((void *)0);
	temp = malloc(size * count);
	if (temp == 0)
		return ((void *)0);
	ft_bzero(temp, (count * size));
	return (temp);
}
