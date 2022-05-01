/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:30:14 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/30 19:32:42 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*temp;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	temp = (int *)malloc(sizeof(int) * (max - min));
	if (temp == 0)
		return (0);
	while (min < max)
	{
		temp[i] = min;
		min++;
		i++;
	}
	return (temp);
}
