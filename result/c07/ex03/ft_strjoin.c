/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:51:58 by sanghwal          #+#    #+#             */
/*   Updated: 2022/05/01 21:30:50 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	mystrcat(char *result, char *str)
{
	int	i;

	i = 0;
	while (result[i])
		i++;
	while (*str)
	{
		result[i] = *str;
		i++;
		str++;
	}
	result[i] = 0;
}

char	*null(void)
{
	char	*result;

	result = (char *)malloc(sizeof(char));
	*result = 0;
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		i;
	char	*result;

	i = 0;
	total_len = 0;
	if (size == 0)
		return (null());
	while (i < size)
	{
		total_len += str_len(strs[i]);
		i++;
	}
	total_len += str_len(sep) * (size - 1);
	result = (char *)malloc(sizeof(char) * total_len + 1);
	result[0] = 0;
	i = 0;
	while (i < size - 1)
	{
		mystrcat(result, strs[i]);
		mystrcat(result, sep);
		i++;
	}
	mystrcat(result, strs[i]);
	return (result);
}
