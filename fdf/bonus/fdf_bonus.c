/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:01:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/15 16:55:44 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int ac, char *av[])
{
	t_meta	meta;

	if (ac < 2)
		exit (1);
	meta.map = map_pars(av[1]);
	if (meta.map == NULL)
		exit(1);
	my_mlx_init(&meta);
	set_scaling_size(meta.map, &meta.img);
	isometric_projection(&meta);
	mlx_put_image_to_window(meta.vars.mlx, meta.vars.win, meta.img.img, 0, 0);
	mlx_hook(meta.vars.win, KEY_PRESS, 0, key_hook, &meta);
	mlx_hook(meta.vars.win, CROSS, 0, exit_fdf, &meta);
	mlx_loop(meta.vars.mlx);
}

int	exit_fdf(t_meta *meta)
{
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
	free_coords(meta->map->coords, meta->map->height);
	free_coords(meta->map->og_coords, meta->map->height);
	free(meta->map);
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
	meta->vars.win = mlx_new_window(meta->vars.mlx, meta->img.width, \
			meta->img.height, "sanghwal");
	meta->img.img = mlx_new_image(meta->vars.mlx, meta->img.width, \
			meta->img.height);
	meta->img.addr = mlx_get_data_addr(meta->img.img, \
		&meta->img.bit_p_p, &meta->img.len, &meta->img.endian);
	meta->img.angles.x = 215;
	meta->img.angles.y = -45;
	meta->img.angles.z = 60;
	meta->map->s_c = WHITE;
	meta->map->e_c = WHITE;
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
	put_img(meta);
}
