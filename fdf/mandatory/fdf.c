/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:01:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/01/03 20:58:54 by sanghwal         ###   ########seoul.kr  */
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
	map_scaling(meta.map->coords, meta.map);
	move_center(&meta, &meta.img, meta.map->coords);
	draw_line(meta.map->coords, &meta.img, meta.map);
	mlx_put_image_to_window(meta.vars.mlx, meta.vars.win, meta.img.img, 0, 0);
	mlx_key_hook(meta.vars.win, key_hook, &meta);
	mlx_loop(meta.vars.mlx);
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

int	key_hook(int keycode, t_meta *meta)
{
	if (keycode == 53)
	{
		mlx_destroy_window(meta->vars.mlx, meta->vars.win);
		exit(0);
	}
	if (keycode >= KEY_LEFT && keycode <= KEY_UP)
	{
		printf("%d\n", keycode);
		memset_img_data(meta, &meta->img);
		rotation_img(keycode, meta);
	}
	return (0);
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
	meta->img.angles.x = 0;
	meta->img.angles.y = 0;
	meta->img.angles.z = 0;
}

void	rotation_img(int keycode, t_meta *meta)
{
	double	angle;

	angle = 15.0;
	if (keycode == KEY_LEFT || keycode == KEY_DOWN)
		angle = -15.0;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotation_y(meta->map, angle * PI / 180);
	if (keycode == KEY_DOWN || keycode == KEY_UP)
		rotation_x(meta->map, angle * PI / 180);
	move_center(meta, &meta->img, meta->map->coords);
	draw_line(meta->map->coords, &meta->img, meta->map);
	mlx_put_image_to_window(meta->vars.mlx, meta->vars.win, meta->img.img, 0, 0);
}

void	memset_img_data(t_meta *meta, t_img *img)
{
	const int	size = img->width * img->height * 4;
	int color;
	
	color = 0;
	color = mlx_get_color_value(meta->vars.mlx, color);
	ft_memset(img->addr, color, size);
}

void	move_center(t_meta * meta, t_img *img, t_coord **coords)
{
	const int	center_x = img->width / 2;
	const int	center_y = img->height / 2;
	const int	move_x = (center_x - coords[meta->map->height / 2][meta->map->width / 2].x);
	const int	move_y = (center_y - coords[meta->map->height / 2][meta->map->width / 2].y);
	int x;
	int y;
	// printf("move_x = %d\n", move_x);
	// printf("move_y = %d\n", move_y);
	y = 0;
	while (y < meta->map->height)
	{
		x = 0;
		while (x < meta->map->width)
		{
			// print_coord(y, x, &coords[y][x]);
			coords[y][x].x += move_x;
			coords[y][x].y += move_y;
			x++;
		}
		y++;
	}
}

