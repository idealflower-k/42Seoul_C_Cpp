/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeongki <byeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:30:38 by byeongki          #+#    #+#             */
/*   Updated: 2022/04/16 20:58:43 by byeongki         ###   ########.fr       */
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
			if ((i_y == 1 || i_y == y) && (j_x == 1 || j_x == x))
				ft_putchar('o');
			else if ((i_y != 1 && i_y != y) && (j_x == 1 || j_x == x))
				ft_putchar('|');
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
