/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:03:58 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/15 16:55:44 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	put_img(t_meta *meta)
{
	map_scaling(meta->map->og_coords, meta->map);
	rotation(meta->map, meta);
	move_center(meta, &meta->img, meta->map->coords);
	draw_line(meta->map->coords, &meta->img, meta->map);
	mlx_put_image_to_window(\
		meta->vars.mlx, meta->vars.win, meta->img.img, 0, 0);
}

void	memset_img_data(t_meta *meta, t_img *img)
{
	const int	size = img->width * img->height * 4;
	int			color;

	color = 0;
	color = mlx_get_color_value(meta->vars.mlx, color);
	ft_memset(img->addr, color, size);
}
