/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:19:12 by sanghwal          #+#    #+#             */
/*   Updated: 2022/05/03 17:22:23 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_size(int size)
{
	if (size > 9)
	{
		print_size(size / 10);
		print_size(size % 10);
	}
	else
	{
		size += '0';
		write(1, &size, 1);
	}
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		print_str(par[i].str);
		write(1, "\n", 1);
		print_size(par[i].size);
		write(1, "\n", 1);
		print_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
