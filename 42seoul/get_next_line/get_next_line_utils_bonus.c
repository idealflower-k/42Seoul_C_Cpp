/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IdealFlower <IdealFlower@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:00:04 by jaewopar          #+#    #+#             */
/*   Updated: 2022/08/01 14:42:21 by IdealFlower      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	len;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, s1, ft_strlen(s1) + 1);
	ft_strlcpy(tmp + ft_strlen(s1), s2, len + 1);
	tmp[len] = '\0';
	return (tmp);
}

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (tmp == 0)
		return (0);
	while (*s1)
	{
		tmp[i] = *s1;
		s1++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	unsigned int	s_len;

	if (s == 0)
		return (0);
	s_len = (unsigned int)ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if ((unsigned int)len > s_len)
		tmp = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else
		tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, s + start, len + 1);
	return (tmp);
}
