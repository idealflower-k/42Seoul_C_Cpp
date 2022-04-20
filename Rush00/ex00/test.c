/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:02:11 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/19 11:09:59 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);

void print(int x, int y)
{
	int i_y;
	int j_x;

	i_y = 1;
	j_x = 1;
	while (i_y <= y)
	{
		while (j_x <= x)
		{
			if((i_y == 1 || i_y ==y) && (j_x == 1 || j_x == x)
					ft_putchar('o');
			else if ((i_y != 1 && i_y != y) && (j_x == 1 || j-x == x))
					ft_putchar('l');
			else if (i_y != 1 && i_y != y && j_x != 1 && j_x != x)
					ft_putchar(' ');
			else
				ft_putchar('-');
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
