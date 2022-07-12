/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:46:33 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/12 15:20:48 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		size;

	size = ft_strlen(src);
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (0);
	size = 0;
	while (src[size])
	{
		temp[size] = src[size];
		size++;
	}
	return (temp);
}
