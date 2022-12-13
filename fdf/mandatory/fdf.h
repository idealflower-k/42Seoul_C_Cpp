/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:50:37 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/13 20:58:25 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>

typedef struct s_map
{
	int		weight;
	int		height;
	char	*map_arr;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_len;
	int		endian;
}	t_data;

t_map	*map_pars(char *file, t_map *map);
void	*ft_malloc(int size);

#endif