/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:53:01 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/07 17:04:52 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *temp;
	const char *s;

	if (dst <= src)
	{
		temp = (char *)dst;
		s = (const char *)src;
		while (len--)
		{
			*temp++ = *s++;
		}
	}
	else
	{
		temp = (char *)dst;
		temp += len;
		s = (const char *)src;
		s += len;
		while (len--)
		{
			*--temp = *--s;
		}
	}
	return (dst);
}
