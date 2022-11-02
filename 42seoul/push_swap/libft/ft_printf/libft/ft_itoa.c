/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:36:33 by sanghwal          #+#    #+#             */
/*   Updated: 2022/09/14 15:14:18 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n);
static int	ft_n_len(int n);

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	long	nb;

	len = ft_n_len(n);
	nb = n;
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (0);
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		result[0] = '0';
	while (nb)
	{
		result[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (result);
}

static int	ft_n_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}
