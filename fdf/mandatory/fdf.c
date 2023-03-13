/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:01:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/13 17:34:25 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_meta	meta;

	if (ac < 2)
		exit (1);
	meta.map = map_pars(av[1]);
	my_mlx_init(&meta);
	set_scaling_size(meta.map, &meta.img);
	isometric_projection(&meta);
	mlx_put_image_to_window(meta.vars.mlx, meta.vars.win, meta.img.img, 0, 0);
	mlx_hook(meta.vars.win, KEY_PRESS, 0, key_hook, &meta);
	mlx_hook(meta.vars.win, 17, 0, exit_fdf, &meta);
	mlx_loop(meta.vars.mlx);
}

int	exit_fdf(t_meta *meta)
{
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
	// free
	exit(0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char		*dst;
	const int	offset = (y * img->len + x * (img->bit_p_p / 8));

	if (x < 0 || y < 0)
		return ;
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

void	my_mlx_init(t_meta *meta)
{
	meta->vars.mlx = mlx_init();
	meta->img.width = 1920;
	meta->img.height = 1080;
	meta->vars.win = mlx_new_window(meta->vars.mlx, meta->img.width, meta->img.height, "sanghwal");
	meta->img.img = mlx_new_image(meta->vars.mlx, meta->img.width, meta->img.height);
	meta->img.addr = mlx_get_data_addr(meta->img.img, \
		&meta->img.bit_p_p, &meta->img.len, &meta->img.endian);
	meta->img.angles.x = 215;
	meta->img.angles.y = -45;
	meta->img.angles.z = 60;
}

void	rotation_img(int keycode, t_meta *meta)
{
	get_og_coords(meta->map, meta->map->coords, meta->map->og_coords);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		{
			if (keycode == KEY_LEFT)
				meta->img.angles.y = (double)(((int)meta->img.angles.y - 1) % 360);
			else
				meta->img.angles.y = (double)(((int)meta->img.angles.y + 1) % 360);
		}
	if (keycode == KEY_DOWN || keycode == KEY_UP)
		{
			if (keycode == KEY_DOWN)
				meta->img.angles.x = (double)(((int)meta->img.angles.x - 1) % 360);
			else
				meta->img.angles.x = (double)(((int)meta->img.angles.x + 1) % 360);
		}
	if (keycode == KEY_Z || keycode == KEY_X)
		{
			if (keycode == KEY_X)
				meta->img.angles.z = (double)(((int)meta->img.angles.z - 1));
			else
				meta->img.angles.z = (double)(((int)meta->img.angles.z + 1));
		}
	map_scaling(meta->map->og_coords, meta->map);
	rotation(meta->map, meta);
	move_center(meta, &meta->img, meta->map->coords);
	draw_line(meta->map->coords, &meta->img, meta->map);
	mlx_put_image_to_window(meta->vars.mlx, meta->vars.win, meta->img.img, 0, 0);
}

void	memset_img_data(t_meta *meta, t_img *img)
{
	const int	size = img->width * img->height * 4;
	int			color;

	color = 0;
	color = mlx_get_color_value(meta->vars.mlx, color);
	ft_memset(img->addr, color, size);
}

void	move_center(t_meta *meta, t_img *img, t_coord **coords)
{
	const int	move_x = (img->width / 2 - \
		coords[meta->map->height / 2][meta->map->width / 2].x);
	const int	move_y = (img->height / 2 - \
		coords[meta->map->height / 2][meta->map->width / 2].y);
	int			x;
	int			y;

	y = 0;
	while (y < meta->map->height)
	{
		x = 0;
		while (x < meta->map->width)
		{
			coords[y][x].x += move_x;
			coords[y][x].y += move_y;
			x++;
		}
		y++;
	}
}
