#include "fdf.h"

int	get_color(t_coord *coord0, t_draw *draw, int step, t_map *map)
{
	const int		total_step = \
		abs((coord0->x - draw->x[1])) + abs((coord0->y - draw->y[1]));
	const double	ratio = 1 - (double)step / total_step;
	int				color;

	color = 0;
	color = get_gradation_color(map->s_c, map->e_c, ratio);
	return (color);
}

int	get_gradation_color(int color1, int color2, double ratio)
{
	int				color;
	int				mask;

	color = 0;
	mask = 0x00FF0000;
	while (mask)
	{
		color |= (int)((color1 & mask) * ratio + (color2 & mask) * (1 - ratio)) \
				& mask;
		mask >>= 8;
	}
	return (color);
}

double	get_ratio(int total, int cur)
{
	return (cur / total);
}
