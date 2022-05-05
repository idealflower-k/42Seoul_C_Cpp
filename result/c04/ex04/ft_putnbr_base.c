/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:58:56 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/30 17:24:45 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == 0 || str_len(base) == 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	change_nbr(unsigned int nbr, int len, char *base)
{
	if (nbr >= (unsigned int)len)
	{
		change_nbr(nbr / len, len, base);
		change_nbr(nbr % len, len, base);
	}
	else
		write(1, &base[nbr], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				len;
	unsigned int	num;

	if (check_base(base) == 0)
		return ;
	len = str_len(base);
	num = 1;
	if (nbr < 0)
	{
		write(1, "-", 1);
		num = nbr * -1;
	}
	else
		num = num * nbr;
	change_nbr(num, len, base);
}
