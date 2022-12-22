/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:05:51 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/22 21:34:52 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

t_map	*map_pars(char *file)
{
	t_map	*map;
	char	**tmp;
		
	map = ft_malloc(sizeof(t_map));
	tmp = read_map(file, map);
	set_vecs(map, tmp);
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
	close(fd);
}

void	set_vecs(t_map *map, char **tmp)
{
	int 	x;
	int		y;
	char	**split_z;
	
	y = 0;
	map->vecs = (t_vec **)ft_malloc((sizeof(t_vec *) * map->height) + 1);
	while (y < map->height)
	{
		x = 0;
		split_z = ft_split(tmp[y], ' ');
		map->vecs[y] = (t_vec *)ft_malloc((sizeof(t_vec) * map->width) + 1);
		while (x < map->width)
		{
			map->vecs[y][x].y = y;
			map->vecs[y][x].x = x;
			map->vecs[y][x].z = ft_atoi(split_z[x]);
			x++;
		}
		free_double_arr(split_z);
		y++;
	}
}
