#include "fdf_bonus.h"

int	bresenham_line_algo(t_draw *draw)
{
	if (draw->x[0] == draw->x[1] && draw->y[0] == draw->y[1])
		return (0);
	draw->e2 = 2 * draw->error;
	if (draw->e2 >= draw->dy)
	{
		if (draw->x[0] == draw->x[1])
			return (0);
		draw->error += draw->dy;
		draw->x[0] += draw->sx;
	}
	else if (draw->e2 <= draw->dx)
	{
		if (draw->y[0] == draw->y[1])
			return (0);
		draw->error += draw->dx;
		draw->y[0] += draw->sy;
	}
	return (1);
}
