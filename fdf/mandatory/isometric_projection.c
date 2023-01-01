/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:18:21 by sanghwal          #+#    #+#             */
/*   Updated: 2023/01/01 15:46:06 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_coord **coords, t_map *map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;

	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			test(&coords[y][x]);
			// rotation_y(&coords[y][x]);
			// rotation_x(&coords[y][x]);
			// rotation_z(&coords[y][x]);
			move_test(&coords[y][x]);
			x++;
		}
		y++;
	}
}

void	move_test(t_coord *coord)
{
	coord->x += 300;
	coord->y += 100;
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

void	rotation_y(t_coord *coord)
{
	const double	t_x = coord->x;
	const double	t_z = coord->z;

	coord->x = ((t_x * cos(BETA)) + (t_z * -sin(BETA))) + 0.5;
	coord->z = ((t_x * sin(BETA)) + (t_z * cos(BETA))) + 0.5;
}

void	rotation_x(t_coord *coord)
{
	const double	t_y = coord->y;
	const double	t_z = coord->z;

	coord->y = ((t_y * cos(ALPHA)) + (t_z * -sin(ALPHA))) + 0.5;
	coord->z = ((t_y * sin(ALPHA)) + (t_z * cos(ALPHA))) + 0.5;
}

void	rotation_z(t_coord *coord)
{
	const double	t_x = coord->x;
	const double	t_y = coord->y;

	coord->x = ((t_x * cos(CHARLEE)) + (t_y * -sin(CHARLEE))) + 0.5;
	coord->y = ((t_x * sin(CHARLEE)) + (t_y * cos(CHARLEE))) + 0.5;
}
