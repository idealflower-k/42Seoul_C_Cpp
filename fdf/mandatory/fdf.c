/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:01:52 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/20 17:14:11 by sanghwal         ###   ########seoul.kr  */
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

int	main(void)
{
	t_data	img;
	t_var	vars;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "hello");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_len, &img.endian);
	my_mlx_pixel_put(&img, 0, 0, 0x000FF000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 200, 200);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}