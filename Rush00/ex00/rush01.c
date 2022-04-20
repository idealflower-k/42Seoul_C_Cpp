/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcho <kcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:07:21 by kcho              #+#    #+#             */
/*   Updated: 2022/04/18 21:12:45 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print(int x, int y)
{
	int	i_y;
	int	j_x;

	i_y = 1;
	j_x = 1;
	while (i_y <= y)
	{
		while (j_x <= x)
		{
			if (i_y == 1 && j_x == 1)
				ft_putchar('/');
			else if ((i_y == y && j_x == x) && (j_x != 1 && i_y != 1))
				ft_putchar('/');
			else if ((i_y == 1 && j_x == x) || (i_y == y && j_x == 1))
				ft_putchar('\\');
			else if (i_y != 1 && i_y != y && j_x != 1 && j_x != x)
				ft_putchar(' ');
			else
				ft_putchar('*');
			j_x++;
		}
		j_x = 1;
		ft_putchar('\n');
		i_y++;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	print(x, y);
}
