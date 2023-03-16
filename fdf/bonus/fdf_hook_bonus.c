/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:53:57 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/15 16:55:44 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
