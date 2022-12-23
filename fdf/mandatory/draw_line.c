/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:37:39 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/23 19:36:37 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_coord **coords, t_img *img, t_map *map)
{
	draw_width(coords, img, map);
	draw_height(coords, img, map);
}

void	draw_width(t_coord **coords, t_img *img, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - 1)
		{
			draw(img, &coords[y][x], &coords[y][x + 1]);
			x++;
		}
		y++;
	}
}

void	draw_height(t_coord **coords, t_img *img, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height - 1)
		{
			draw(img, &coords[y][x], &coords[y + 1][x]);
			y++;
		}
		x++;
	}
}

void	draw(t_img *img, t_coord *coord0, t_coord *coord1)
{
	t_draw	*draw;

	draw = set_draw(coord0, coord1);
	while (draw)
	{
		my_mlx_pixel_put(img, draw->x[0], draw->y[0], 0x000FF000);
		if (draw->x[0] == draw->x[1] && draw->y[0] == draw->y[1])
			break ;
		draw->e2 = 2 * draw->error;
		if (draw->e2 >= draw->dy)
		{
			if (draw->x[0] == draw->x[1])
				break ;
			draw->error += draw->dy;
			draw->x[0] += draw->sx;
		}
		else if (draw->e2 <= draw->dx)
		{
			if (draw->y[0] == draw->y[1])
				break ;
			draw->error += draw->dx;
			draw->y[0] += draw->sy;
		}
	}
	free(draw);
}

t_draw	*set_draw(t_coord *coord0, t_coord *coord1)
{
	t_draw	*draw;

	if (!coord0 || !coord1)
		return (0);
	draw = ft_malloc(sizeof(t_draw));
	draw->x[0] = coord0->x;
	draw->x[1] = coord1->x;
	draw->y[0] = coord0->y;
	draw->y[1] = coord1->y;
	draw->dx = abs(coord1->x - coord0->x);
	draw->dy = -abs(coord1->y - coord0->y);
	draw->error = draw->dx + draw->dy;
	draw->sx = -1;
	draw->sy = -1;
	if (coord1->x > coord0->x)
		draw->sx = 1;
	if (coord1->y > coord0->y)
		draw->sy = 1;
	return (draw);
}
