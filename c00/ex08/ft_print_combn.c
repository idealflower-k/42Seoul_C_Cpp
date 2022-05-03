/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:23:20 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/21 12:01:01 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	c = c + '0';
	write(1, &c, 1);
}

void	ft_print(int curr_i, int s_nb, int n, int digit[])
{
	int	i;
	int	curr_nb;

	i = 0;
	if (curr_i == n)
	{
		while (i < n)
			ft_putchar(digit[i++]);
		if (digit[0] != (10 - n))
			write(1, ", ", 2);
	}
	else
	{
		curr_nb = s_nb;
		while (curr_nb < 10)
		{
			digit[curr_i] = curr_nb;
			ft_print(curr_i + 1, curr_nb + 1, n, digit);
			curr_nb++;
		}
	}
}

void	ft_print_combn(int n)
{
	int	curr_i;
	int	s_nb;
	int	digit[10];

	curr_i = 0;
	s_nb = 0;
	ft_print(curr_i, s_nb, n, digit);
}
