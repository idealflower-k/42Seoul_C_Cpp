/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:04:13 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/24 11:22:32 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ch_hexa(unsigned char str)
{
	write(1, &"0123456789abcdef"[str / 16], 1);
	write(1, &"0123456789abcdef"[str % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	temp;

	i = 0;
	temp = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			temp = str[i];
			ch_hexa(temp);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
