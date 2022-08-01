/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IdealFlower <IdealFlower@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:01:04 by jaewopar          #+#    #+#             */
/*   Updated: 2022/08/01 17:19:11 by IdealFlower      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_enter(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

static char	*ft_rdline(int fd, char *buf, char **backup)
{
	int			byte;
	char		*tmp;

	byte = 1;
	while (byte)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
			return (0);
		else if (byte == 0)
			break ;
		buf[byte] = '\0';
		if (!(*backup))
			*backup = ft_strdup("");
		tmp = *backup;
		*backup = ft_strjoin(tmp, buf);
		if (!(*backup))
			return (0);
		free(tmp);
		if (ft_get_enter(buf, '\n'))
			break ;
	}
	return (*backup);
}

static char	*ft_line(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!tmp)
		return (0);
	if (tmp[0] == '\0')
	{
		free(tmp);
		return (0);
	}
	line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*line;
	static char		*backup[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = ft_rdline(fd, buf, &backup[fd]);
	free(buf);
	if (!line)
		return (0);
	backup[fd] = ft_line(line);
	return (line);
}
