#include "minirt.h"
#include "defs.h"
#include "utils.h"

int	destroy(t_meta *meta)
{
	mlx_destroy_image(meta->mlx_assets.mlx, meta->mlx_assets.img.img);
	mlx_destroy_window(meta->mlx_assets.mlx, meta->mlx_assets.win);
	mlx_del(meta->mlx_assets.mlx);
	ft_lstclear(&meta->spot_lights, free);
	objs_clear(&meta->objs, free);
	free(meta);
	exit(EXIT_SUCCESS);
}
