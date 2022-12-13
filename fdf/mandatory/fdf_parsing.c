/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:46:26 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/13 20:59:49 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
t_map	*map_pars(char *file, t_map *map);
void	*ft_malloc(int size);

t_map	*map_pars(char *file, t_map *map)
{
	//	height, map요소 저장 -> gnl 읽으면서 문자열을 map_arr(arr의 사이즈는?, 하나의 문자열로 join 하고 \n 을 기준으로 split?)에 넣고 height++
	int			fd = open(file, O_RDONLY);
	char		*one_line;
	char		*tmp_line;
	
	if (fd == -1)
	{
		perror("file open error");
		exit(1);
	}
	one_line = get_next_line(fd);
	tmp_line = ft_strdup("");
	map->map_arr = tmp_line;
	while (one_line && map->map_arr)
	{
		map->height++;
		map->map_arr = ft_strjoin(tmp_line, one_line);
		free(one_line);
		free(tmp_line);
		one_line = get_next_line(fd);
		tmp_line = map->map_arr;
	}
	free(one_line);
	close(fd);
	return (map);
	//	weight 저장 -> map_arr 순회 (int형으로 저장 필요?)
}

void	*ft_malloc(int size)
{
	void	*this = malloc(size);
	if (!this)
	{
		perror("malloc fail");
		exit(1);
	}
	return (this);
}

int	main(int ac, char *av[])
{
	ac = 0;
	t_map	*map = ft_malloc(sizeof(t_map));
	
	map = map_pars(av[1], map);
	ft_printf("%s\n", map->map_arr);
	return (0);
}