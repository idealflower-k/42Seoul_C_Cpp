/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:50:37 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/21 21:41:17 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include<fcntl.h>
# include<stdlib.h>
# include<math.h>
# include<stdio.h>

typedef struct s_var
{
	void	*mlx;
	void	*win;
}	t_var;


typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_xyz
{
	int	x;
	int	y;
	int z;
}	t_xyz;


typedef struct s_map
{
	int		width;
	int		height;
	t_xyz	**xyzs;
}	t_map;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_var *vars);
void	draw_plus(t_data *data, int *x, int *y, int color);
void	draw_minus(t_data *data, int *x, int *y, int color);

t_map	*map_pars(char *file);
char	**read_map(char *file, t_map *map);
void	set_height(char *file, t_map *map);
void	set_xyzs(t_map *map, char **tmp);

void	*ft_malloc(size_t size);
#endif