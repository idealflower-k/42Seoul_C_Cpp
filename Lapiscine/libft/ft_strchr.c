/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:28:00 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/07 20:19:17 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
	{
		return ((char *)s + ft_strlen(s));
	}
	while (*s)
	{
		if ((char)c == *s)
		{
			return ((char *)s);
		}
		s++;
	}
	return (0);
}
