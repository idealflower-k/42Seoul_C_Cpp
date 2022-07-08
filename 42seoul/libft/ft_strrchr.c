/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:36:40 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/08 15:52:54 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;

	temp = 0;
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if ((char)c == *s)
			temp = s;
		s++;
	}
	return ((char *)temp);
}
