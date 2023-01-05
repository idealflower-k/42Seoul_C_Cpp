/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:18:21 by sanghwal          #+#    #+#             */
/*   Updated: 2023/01/05 13:55:45 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation(t_map *map, t_meta *meta)
{
	rotation_z(map, meta->img.angles.z * PI / 180);
	rotation_x(map, meta->img.angles.x * PI / 180);
	rotation_y(map, meta->img.angles.y * PI / 180);
}

void	rotation_y(t_map *map, double angle)
{
	int	y;
	int	x;
	int	t_x;
	int	t_z;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			t_x = map->coords[y][x].x;
			t_z = map->coords[y][x].z;
			map->coords[y][x].x = ((t_x * cos(angle)) + (t_z * -sin(angle)) + 0.5);
			map->coords[y][x].z = ((t_x * sin(angle)) + (t_z * cos(angle)) + 0.5);
			x++;
		}
		y++;
	}
}


void	rotation_x(t_map *map, double angle)
{
	int	y;
	int	x;
	int	t_y;
	int	t_z;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			t_y = map->coords[y][x].y;
			t_z = map->coords[y][x].z;
			map->coords[y][x].y = ((t_y * cos(angle)) + (t_z * -sin(angle)) + 0.5);
			map->coords[y][x].z = ((t_y * sin(angle)) + (t_z * cos(angle)) + 0.5);
			x++;
		}
		y++;
	}
}

void	rotation_z(t_map *map, double angle)
{
	int	y;
	int	x;
	int	t_y;
	int	t_x;

	if (angle == 0.0)
		return ;
	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			t_y = map->coords[y][x].y;
			t_x = map->coords[y][x].x;
			map->coords[y][x].x = (((double)t_x * sin(angle)) + ((double)t_y * cos(angle)) + 0.5);
			map->coords[y][x].y = (((double)t_x * cos(angle)) + ((double)t_y * -sin(angle)) + 0.5);
			x++;
		}
		y++;
	}	
}

// void	test(t_coord *coord)
// {
// 	double	iso_angle = PI / 6.0f;
// 	const double	x = coord->x;
// 	const double	y = coord->y;
// 	const double	z = coord->z;

// 	coord->x = cos(iso_angle) * x - cos(iso_angle) * y;
// 	coord->y = sin(iso_angle) * x + sin(iso_angle) * y - z;
// }