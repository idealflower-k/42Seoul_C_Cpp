/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:20:47 by sanghwal          #+#    #+#             */
/*   Updated: 2023/01/14 16:23:38 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_meta *meta)
{
	map_scaling(meta->map->coords, meta->map);
	set_angle(&meta->img, 35, 45, -30);
	printf("x: %f, y: %f, z: %f\n", meta->img.angles.x, meta->img.angles.y, meta->img.angles.z);
	printf("%f\n", meta->img.angles.z * PI / 180);
	printf("%f\n", meta->img.angles.y * PI / 180);
	printf("%f\n", meta->img.angles.x * PI / 180);
	rotation(meta->map, meta);
	move_center(meta, &meta->img, meta->map->coords);
	draw_line(meta->map->coords, &meta->img, meta->map);
}

void	set_angle(t_img *img, int x_a, int y_a, int z_a)
{
	img->angles.x = (double)(((int)img->angles.x + x_a) % 360);
	img->angles.y = (double)(((int)img->angles.y + y_a) % 360);
	img->angles.z = (double)(((int)img->angles.z + z_a) % 360);
}
