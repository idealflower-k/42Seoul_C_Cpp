/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:53:57 by sanghwal          #+#    #+#             */
/*   Updated: 2023/01/05 13:54:13 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_meta *meta)
{
	if (keycode == 53)
	{
		mlx_destroy_window(meta->vars.mlx, meta->vars.win);
		exit(0);
	}
	if ((keycode >= KEY_LEFT && keycode <= KEY_UP) || keycode == 6 || keycode == 7 || keycode == 15)
	{
		printf("%d\n", keycode);
		memset_img_data(meta, &meta->img);
		rotation_img(keycode, meta);
	}
	return (0);
}