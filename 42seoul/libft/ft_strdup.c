/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:46:33 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/08 15:48:48 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		size;

	size = 0;
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
