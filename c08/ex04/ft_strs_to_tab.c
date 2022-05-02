/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:13:39 by sanghwal          #+#    #+#             */
/*   Updated: 2022/05/02 21:36:33 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*temp;
	int		len;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!temp)
		return (0);
	len = 0;
	while (*str)
		temp[len++] = *str++;
	temp[len] = 0;
	return (temp);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*temp;
	int			i;

	temp = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!temp)
		return (0);
	i = 0;
	while (i < ac)
	{
		temp[i].size = ft_strlen(av[i]);
		temp[i].str = av[i];
		temp[i].copy = ft_strdup(av[i]);
		i++;
	}
	temp[i].size = 0;
	temp[i].str = 0;
	temp[i].copy = 0;
	return (temp);
}
