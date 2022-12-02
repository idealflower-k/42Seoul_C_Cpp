/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:53:01 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/11 16:16:12 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*temp;
	unsigned const char	*s;

	if (dst == src)
		return (dst);
	if (dst <= src)
	{
		temp = (unsigned char *)dst;
		s = (unsigned const char *)src;
		while (len--)
		{
			*temp++ = *s++;
		}
	}
	else
	{
		temp = (unsigned char *)dst;
		temp += len;
		s = (unsigned const char *)src + len;
		while (len--)
		{
			*--temp = *--s;
		}
	}
	return (dst);
}
