/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:36:40 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/20 16:27:26 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;

	temp = 0;
	while (*s)
	{
		if ((char)c == *s)
			temp = s;
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return ((char *)temp);
}
