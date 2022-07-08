/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:41:12 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/08 15:53:16 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haysack, const char *needle, size_t len);

char	*ft_strnstr(const char *haysack, const char *needle, size_t len)
{
	size_t	i;

	if (needle[0] == 0)
		return ((char *)haysack);
	while (*haysack != 0 && len > 0)
	{
		i = 0;
		while (*(haysack + i) == *(needle + i) && i < len)
		{
			i++;
			if (*(needle + i) == 0)
				return ((char *)haysack);
		}
		haysack++;
		len--;
	}
	return (0);
}
