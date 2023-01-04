// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   draw_utils.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/01/04 16:17:24 by sanghwal          #+#    #+#             */
// /*   Updated: 2023/01/04 16:22:31 by sanghwal         ###   ########seoul.kr  */
// /*                                                                            */
// /* ************************************************************************** */

// #include "fdf.h"

// void	draw_axis(t_map *map, t_img *img)
// {
// 	int	x;
// 	int y;

// 	x = img->width / 2;
// 	y = img->height / 2;
// 	while (x < img->width)
// 	{
		
// 	}
// }

// void	draw_axis_x(t_img *img, int x0, int x1)
// {
// 	t_draw	*draw;
// 	int		color;	

// 	color = GREEN;
// 	draw = set_draw(coord0, coord1);
// 	while (draw)
// 	{
// 		my_mlx_pixel_put(img, draw->x[0], draw->y[0], color);
// 		if (draw->x[0] == draw->x[1] && draw->y[0] == draw->y[1])
// 			break ;
// 		draw->e2 = 2 * draw->error;
// 		if (draw->e2 >= draw->dy)
// 		{
// 			if (draw->x[0] == draw->x[1])
// 				break ;
// 			draw->error += draw->dy;
// 			draw->x[0] += draw->sx;
// 		}
// 		else if (draw->e2 <= draw->dx)
// 		{
// 			if (draw->y[0] == draw->y[1])
// 				break ;
// 			draw->error += draw->dx;
// 			draw->y[0] += draw->sy;
// 		}
// 	}
// 	free(draw);
// }

// t_draw	*set_draw(t_coord *coord0, t_coord *coord1)
// {
// 	t_draw	*draw;

// 	if (!coord0 || !coord1)
// 		return (0);
// 	draw = ft_malloc(sizeof(t_draw));
// 	draw->x[0] = coord0->x;
// 	draw->x[1] = coord1->x;
// 	draw->y[0] = coord0->y;
// 	draw->y[1] = coord1->y;
// 	draw->z[0] = coord0->z;
// 	draw->z[1] = coord1->z;
// 	draw->dx = abs(coord1->x - coord0->x);
// 	draw->dy = -abs(coord1->y - coord0->y);
// 	draw->error = draw->dx + draw->dy;
// 	draw->sx = 1;
// 	draw->sy = 1;
// 	if (coord1->x < coord0->x)
// 		draw->sx = -1;
// 	if (coord1->y < coord0->y)
// 		draw->sy = -1;
// 	return (draw);
// }