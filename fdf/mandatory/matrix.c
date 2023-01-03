/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:47:34 by sanghwal          #+#    #+#             */
/*   Updated: 2023/01/03 20:04:43 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*matrix1(t_coord *coord)
{
	int	*mr1;

	mr1 = ft_malloc(sizeof(int) * 3);
	mr1[0] = coord->x;
	mr1[1] = coord->y;
	mr1[2] = coord->z;
	return (mr1);
}

void	map_scaling(t_coord **coord, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			scaling(&coord[y][x], map);
			x++;
		}
		y++;
	}
}

void	scaling(t_coord *coord, t_map *map)
{
	coord->x = map->scale_size * coord->x;
	coord->y = map->scale_size * coord->y;
	coord->z = 5 * coord->z;
}
