/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:09:16 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/16 20:58:56 by byeongki         ###   ########.fr       */
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
			if (j_x == 1 && (i_y == 1 || i_y == y))
				ft_putchar('A');
			else if (j_x == x && (i_y == 1 || i_y == y))
				ft_putchar('C');
			else if (i_y != 1 && i_y != y && j_x != 1 && j_x != x)
				ft_putchar(' ');
			else
				ft_putchar('B');
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
