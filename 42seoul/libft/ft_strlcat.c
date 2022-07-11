/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:46:55 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/11 17:49:00 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	new_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	new_len = size - dest_len;
	if (size <= dest_len)
		return (src_len + size);
	while (i < new_len - 1 && src[i] && size != 0)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
