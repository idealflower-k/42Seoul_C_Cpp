/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:58:56 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/29 22:09:36 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_len(char *base)
{
	unsigned int	len;

	len = 0;
	while (base[len])
			len++;
	return (len);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base_len(base) <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
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

void	ft_change_nbr(unsigned int nbr, unsigned int len, char *base)
{
	if (nbr >= len)
	{
		ft_change_nbr(nbr / len, len, base);
		ft_change_nbr(nbr % len, len, base);
	}
	else
		write(1, &base[nbr], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;
	unsigned int	un_nbr;

	un_nbr = 0;
	len = base_len(base);
	if (check_base(base) == 0)
		return ;
	else if (nbr < 0)
	{
		write(1, "-", 1);
		un_nbr = nbr * -1;
	}
	else
		un_nbr = nbr;
	ft_change_nbr(un_nbr, len, base);
}
