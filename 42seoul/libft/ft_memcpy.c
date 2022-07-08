/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:13:46 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/07 16:34:55 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*s;

	temp = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n--)
	{
		*temp++ = *s++;
	}
	return (dst);
}
