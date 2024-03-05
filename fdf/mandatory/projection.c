#include "fdf.h"

void	isometric_projection(t_meta *meta)
{
	map_scaling(meta->map->coords, meta->map);
	rotation(meta->map, meta);
	move_center(meta, &meta->img, meta->map->coords);
	draw_line(meta->map->coords, &meta->img, meta->map);
}
