/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:20:47 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/13 17:35:34 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_meta *meta)
{
	map_scaling(meta->map->coords, meta->map);
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
