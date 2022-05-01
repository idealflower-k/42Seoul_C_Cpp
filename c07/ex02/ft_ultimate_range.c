/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:51:20 by sanghwal          #+#    #+#             */
/*   Updated: 2022/05/01 15:19:13 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*temp;

	size = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	temp = (int *)malloc(sizeof(int) * (max - min));
	if (temp == 0)
		return (-1);
	while (min < max)
	{
		temp[size] = min;
		size++;
		min++;
	}
	*range = temp;
	return (size);
}
