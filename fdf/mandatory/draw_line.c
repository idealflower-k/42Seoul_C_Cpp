/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:52:01 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/21 19:38:30 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_minus(t_data *data, int *x, int *y, int color)
{
	int	dx;
	int	dy;
	int	p;
	int	tx;
	int	ty;
	
	dx = x[1] - x[0];
	dy = y[1] - y[0];
	
	tx = x[0];
	ty = y[0];

	p = (2 * dy) - dx;
	
	while (tx < x[1])
	{
		if (p >= 0)
		{
			my_mlx_pixel_put(data, tx, ty, color);
			ty += 1;
			p = p + 2 *(dy - dx);
		}
		else
		{
			my_mlx_pixel_put(data, tx, ty, color);
			p = p + (2*dy);
		}
		tx += 1;
	}
}

void	draw_plus(t_data *data, int *x, int *y, int color)
{
	int	dx;
	int	dy;
	int	p;
	int	tx;
	int	ty;
	
	dx = x[1] - x[0];
	dy = y[1] - y[0];
	
	tx = x[0];
	ty = y[0];

	p = (2 * dx) - dy;
	while (ty < y[1])
	{
		if (p >= 0)
		{
			my_mlx_pixel_put(data, tx, ty, color);
			tx += 1;
			p = p + 2 *(dx - dy);
		}
		else
		{
			my_mlx_pixel_put(data, tx, ty, color);
			p = p + (2*dx);
		}
		ty += 1;
	}
}
