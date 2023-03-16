/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:38:45 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/15 16:55:44 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_scaling_size(t_map *map, t_img *img)
{
	double	width_size;
	double	height_size;

	width_size = 0;
	height_size = 0;
	while (map->width * width_size < img->width)
		width_size += 0.2;
	while (map->height * height_size < img->height)
		height_size += 0.2;
	if (width_size < height_size)
		map->scale_size = width_size - 0.2;
	else
		map->scale_size = height_size - 0.2;
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
