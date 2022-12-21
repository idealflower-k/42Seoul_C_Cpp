/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:01:52 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/21 21:39:28 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	const	int offset = (y * data->line_len + x * (data->bit_per_pixel / 8));
	
	dst = data->addr + offset;
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

// int	main(int ac, int *av[])
// {
// 	t_data	img;
// 	t_var	vars;
// 	int		x[2];
// 	int		y[2];
	
// 	x[0] = 0;
// 	y[0] = 100;
// 	x[1] = 400;
// 	y[1] = 100;
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "hello");
// 	img.img = mlx_new_image(vars.mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_len, &img.endian);
// 	draw_plus(&img, x, y, 0x000FF000);
// 	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 200, 200);
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }

int main(int ac, char *av[])
{
	ac = 0;
	t_map	*map;
	
	map = map_pars(av[1]);

	printf("y: %d | x: %d | z: %d", map->xyzs[0][0].y, map->xyzs[0][0].x, map->xyzs[0][0].z);
}