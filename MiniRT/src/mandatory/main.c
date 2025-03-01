#include "defs.h"
#include "design_patterns.h"
#include "hooks.h"
#include "minirt.h"
#include "parser.h"
#include "render.h"
#include "scene.h"
#include "utils.h"

static bool	_is_rtfile(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext || ext == file)
		return (false);
	if (ft_strcmp(ext, ".rt"))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_meta	*meta;

	if (ac != 2)
		error_handler(ARGS_ERR);
	if (!_is_rtfile(av[1]))
		error_handler(EX_ERR);
	parser(open(av[1], O_RDONLY));
	meta = singleton();
	setup_scene(meta, WIN_WIDTH, WIN_HEIGHT);
	render(meta);
	hooks(meta);
	mlx_loop(meta->mlx_assets.mlx);
	destroy(meta);
	return (EXIT_SUCCESS);
}
