/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:18:21 by sanghwal          #+#    #+#             */
/*   Updated: 2023/01/03 20:58:36 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_test(t_coord *coord)
{
	coord->x += 300;
	coord->y += 200;
}

void	test(t_coord *coord)
{
	double	iso_angle = PI / 6.0f;
	const double	x = coord->x;
	const double	y = coord->y;
	const double	z = coord->z;

	coord->x = cos(iso_angle) * x - cos(iso_angle) * y;
	coord->y = sin(iso_angle) * x + sin(iso_angle) * y - z;
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
			// move_test(&map->coords[y][x]);
			x++;
		}
		y++;
	}
}

void	print_coord(int y, int x, t_coord *coord)
{
	printf("y%d= %d, x%d= %d\n", y, coord->y, x, coord->x);
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
			map->coords[y][x].y = ((t_y * cos(angle)) + (t_z * -sin(angle)));
			map->coords[y][x].z = ((t_y * sin(angle)) + (t_z * cos(angle)));
			x++;
		}
		y++;
	}
}

// void	rotation_z(t_coord *coord, double angle)
// {
// 	const double	t_x = coord->x;
// 	const double	t_y = coord->y;

// 	coord->x = ((t_x * cos(angle)) + (t_y * -sin(angle))) + 0.5;
// 	coord->y = ((t_x * sin(angle)) + (t_y * cos(angle))) + 0.5;
// }
