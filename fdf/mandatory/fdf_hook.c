#include "fdf.h"

int	key_hook(int keycode, t_meta *meta)
{
	if (keycode == KEY_ESC)
		exit_fdf(meta);
	if ((keycode >= KEY_LEFT && keycode <= KEY_UP) \
		|| keycode == KEY_Z || keycode == KEY_X || keycode == KEY_R)
	{
		memset_img_data(meta, &meta->img);
		rotation_img(keycode, meta);
	}
	return (0);
}
