/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:32:59 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/30 16:27:13 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*temp;
	int		size;

	size = 0;
	if (src[size] == 0)
		return (0);
	while (src[size])
		size++;
	temp = (char *)malloc(sizeof(char) * size + 1);
	if (temp == 0)
		return (0);
	size = 0;
	while (*src)
	{
		temp[size] = *src;
		size++;
		src++;
	}
	temp[size] = 0;
	return (temp);
}
