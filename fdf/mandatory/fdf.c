/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:01:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/01/01 15:45:29 by sanghwal         ###   ########seoul.kr  */
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
	t_img	img;
	t_var	vars;
	t_map	*map;

	if (ac < 2)
		exit (1);
	map = map_pars(av[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 800, "hello");
	img.img = mlx_new_image(vars.mlx, 1000, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bit_p_p, &img.len, &img.endian);
	vars.img = &img;
	map->size = 30;
	map_scaling(map->coords, map);
	isometric_projection(map->coords, map);
	draw_line(map->coords, &img, map);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 50, 50);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
