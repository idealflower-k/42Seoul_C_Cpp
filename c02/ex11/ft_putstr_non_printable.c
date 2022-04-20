/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:04:13 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/20 16:57:14 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ch_hexa(int i, char *str)
{
	int	hexa;

	hexa = 0;
	write(1, &"012345679abcdef"[str[i] / 16], 1);
	write(1, &"0123456789abcdef"[str[i] % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 33 || str[i] > 127)
		{
			write(1, "\\", 1);
			ch_hexa(i, str);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
