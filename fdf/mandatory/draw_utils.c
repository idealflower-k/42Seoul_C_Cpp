#include "fdf.h"

t_draw	*set_draw(t_coord *coord0, t_coord *coord1)
{
	t_draw	*draw;

	if (!coord0 || !coord1)
		return (0);
	draw = ft_malloc(sizeof(t_draw));
	draw->x[0] = coord0->x;
	draw->x[1] = coord1->x;
	draw->y[0] = coord0->y;
	draw->y[1] = coord1->y;
	draw->z[0] = coord0->z;
	draw->z[1] = coord1->z;
	draw->dx = abs(coord1->x - coord0->x);
	draw->dy = -abs(coord1->y - coord0->y);
	draw->error = draw->dx + draw->dy;
	draw->sx = 1;
	draw->sy = 1;
	if (coord1->x < coord0->x)
		draw->sx = -1;
	if (coord1->y < coord0->y)
		draw->sy = -1;
	return (draw);
}

int	bresenham_line_algo(t_draw *draw)
{
	if (draw->x[0] == draw->x[1] && draw->y[0] == draw->y[1])
		return (0);
	if (draw->error >= draw->dy)
	{
		if (draw->x[0] == draw->x[1])
			return (0);
		draw->error += draw->dy;
		draw->x[0] += draw->sx;
	}
	else if (draw->error <= draw->dx)
	{
		if (draw->y[0] == draw->y[1])
			return (0);
		draw->error += draw->dx;
		draw->y[0] += draw->sy;
	}
	return (1);
}
