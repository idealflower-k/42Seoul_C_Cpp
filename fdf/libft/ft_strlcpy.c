/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:38:57 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/11 16:32:52 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (i < dstsize - 1 && src[i] && dstsize != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dest[i] = '\0';
	return (src_len);
}
