/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:01:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/01/01 16:17:04 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char		*dst;
	const int	offset = (y * img->len + x * (img->bit_p_p / 8));

	if (x < 0 || y < 0)
		return ;
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_var *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		// system("leaks fdf");
		exit(0);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_meta	meta;
	t_map	*map;

	if (ac < 2)
		exit (1);
	map = map_pars(av[1]);
	my_mlx_init(&meta);
	map->size = 30;
	map_scaling(map->coords, map);
	isometric_projection(map->coords, map);
	draw_line(map->coords, &meta.img, map);
	mlx_put_image_to_window(meta.vars.mlx, meta.vars.win, meta.img.img, 50, 50);
	mlx_key_hook(meta.vars.win, key_hook, &meta.vars);
	mlx_loop(meta.vars.mlx);
}

void	my_mlx_init(t_meta *meta)
{
	meta->vars.mlx = mlx_init();
	meta->vars.win = mlx_new_window(meta->vars.mlx, 1000, 800, "sanghwal");
	meta->img.img = mlx_new_image(meta->vars.mlx, 1000, 800);
	meta->img.addr = mlx_get_data_addr(meta->img.img, \
		&meta->img.bit_p_p, &meta->img.len, &meta->img.endian);
}
