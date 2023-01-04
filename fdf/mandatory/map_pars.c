/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:05:51 by sanghwal          #+#    #+#             */
/*   Updated: 2023/01/04 20:40:53 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map_pars(char *file)
{
	t_map	*map;
	char	**tmp;

	map = ft_malloc(sizeof(t_map));
	tmp = read_map(file, map);
	set_coords(map, tmp);
	free_double_arr(tmp);
	return (map);
}

char	**read_map(char *file, t_map *map)
{
	char	**tmp;
	int		i;
	int		fd;

	set_height(file, map);
	tmp = ft_malloc((sizeof(char *) * map->height) + 1);
	fd = open(file, O_RDONLY);
	i = 0;
	tmp[i] = get_next_line(fd);
	set_width(tmp[i], map);
	while (tmp[i])
	{
		i++;
		tmp[i] = get_next_line(fd);
	}
	return (tmp);
}

void	set_width(char *str, t_map *map)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	while (tmp[map->width] != 0)
		map->width++;
	free_double_arr(tmp);
}

void	set_height(char *file, t_map *map)
{
	int		fd;
	char	*tmp;

	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		map->height++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	close(fd);
}

void	set_coords(t_map *map, char **tmp)
{
	int		x;
	int		y;
	char	**split_z;

	y = 0;
	map->og_coords = (t_coord **)ft_malloc((sizeof(t_coord *) * map->height));
	while (y < map->height)
	{
		x = 0;
		split_z = ft_split(tmp[y], ' ');
		map->og_coords[y] = (t_coord *)ft_malloc((sizeof(t_coord) * \
				map->width));
		while (x < map->width)
		{
			map->og_coords[y][x].y = y;
			map->og_coords[y][x].x = x;
			map->og_coords[y][x].z = -1 * ft_atoi(split_z[x]);
			x++;
		}
		free_double_arr(split_z);
		y++;
	}
	copy_coords(map, map->og_coords);
}
