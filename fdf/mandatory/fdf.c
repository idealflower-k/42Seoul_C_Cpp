/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:01:52 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/22 21:49:58 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	const	int offset = (y * img->line_len + x * (img->bit_per_pixel / 8));
	
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_var *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_img	img;
	t_var	vars;
	t_map	*map;

	map = map_pars(av[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "hello");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_len, &img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 200, 200);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

// int main(int ac, char *av[])
// {
// 	ac = 0;
// 	t_map	*map;
	
// 	map = map_pars(av[1]);

// 	for (int y = 0; y < map->height; y++)
// 	{
// 		for (int x = 0; x < map->width; x++)
// 			printf("%d ", map->vecs[y][x].z);
// 		printf("\n");
// 	}
// }