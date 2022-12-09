/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:46:20 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/09 18:04:30 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
void	draw_circle(t_data *img, int *size);
int	get_distance(int x, int y, int *center);
int ft_sqrt(int nb);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int get_offset_img(int x, int y, int line_len, int bits_per_pixel);
int	main(void)
{
	void		*mlx;
	void		*mlx_window;
	const int	size[2] = {800, 800};
	t_data		*img;
	
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, size[0], size[1], "hello");
	img = malloc(sizeof(t_data));
	ft_memset(img, 0, sizeof(img));
	img->img = mlx_new_image(mlx, size[0], size[1]);
	img->addr = mlx_get_data_addr(img->img, &img->bit_per_pixel, &img->line_len, &img->endian);
	draw_circle(img, (int *)&size);
	printf("line len : %d\n", img->line_len);
	mlx_put_image_to_window(mlx, mlx_window, img->img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

void	draw_circle(t_data *img, int *size)
{
	int	i;
	int	j;
	const int center[2] = {size[0] / 2, size[1] / 2};
	const int circle_r = get_distance(center[0], size[1], (int *)&center);
	
	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			if (get_distance(i, j, (int *)&center) <= circle_r)
				my_mlx_pixel_put(img, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}

int	get_distance(int x, int y, int *center)
{
	int square_res;
	square_res = (x - center[0]) * (x - center[0]) + (y - center[1]) * (y - center[1]);
	return (ft_sqrt(square_res));
}

int ft_sqrt(int nb)
{
	long long	i;
	
	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + get_offset_img(x, y, data->line_len, data->bit_per_pixel);
	*(unsigned int *)dst = color;
}

int get_offset_img(int x, int y, int line_len, int bits_per_pixel)
{
	return (y * line_len + x * (bits_per_pixel / 8));
}