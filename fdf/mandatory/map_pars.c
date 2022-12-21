/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:05:51 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/21 21:50:51 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

t_map	*map_pars(char *file)
{
	t_map	*map;
	char	**tmp;
		
	map = ft_malloc(sizeof(t_map));
	tmp = read_map(file, map);
	set_xyzs(map, tmp);
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
	map->width = ft_strlen(tmp[i]) / 2;
	tmp[i][(map->width * 2) - 1] = 0;
	while (tmp[i])
	{
		i++;
		tmp[i] = get_next_line(fd);
		if (tmp[i])
			tmp[i][(map->width * 2) - 1] = 0;
	}
	return (tmp);
}

void	set_height(char *file, t_map *map)
{
	int	fd;
	
	fd = open(file, O_RDONLY);
	while (get_next_line(fd))
		map->height++;
	close(fd);
}

void	set_xyzs(t_map *map, char **tmp)
{
	int 	x;
	int		y;
	char	**split_z;
	
	y = 0;
	map->xyzs = (t_xyz **)ft_malloc((sizeof(t_xyz *) * map->height) + 1);
	while (y < map->height)
	{
		x = 0;
		split_z = ft_split(tmp[y], ' ');
		map->xyzs[y] = (t_xyz *)ft_malloc((sizeof(t_xyz) * map->width) + 1);
		while (x < map->width)
		{
			map->xyzs[y][x].y = y;
			map->xyzs[y][x].x = x;
			map->xyzs[y][x].z = ft_atoi(split_z[x]);
			x++;
		}
		y++;
	}
}