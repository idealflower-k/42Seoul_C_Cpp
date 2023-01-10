/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:38:45 by sanghwal          #+#    #+#             */
/*   Updated: 2023/01/06 14:05:46 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_scaling_size(t_map *map, t_img *img)
{
	int	width_size;
	int	height_size;

	width_size = 0;
	height_size = 0;
	while (map->width * width_size < img->width * (2.0 / 3.0))
		width_size++;
	while (map->height * height_size < img->height * (2.0 / 3.0))
		height_size++;
	if (width_size < height_size)
		map->scale_size = width_size - 1;
	else
		map->scale_size = height_size - 1;
}

void	map_scaling(t_coord **og_coord, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			scaling(&og_coord[y][x], &map->coords[y][x], map);
			x++;
		}
		y++;
	}
}
