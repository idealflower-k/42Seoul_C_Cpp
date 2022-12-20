/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:50:37 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/20 16:00:11 by sanghwal         ###   ########seoul.kr  */
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


#endif