/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:51:21 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/29 18:01:37 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "libft.h"

char	*ft_unsigned_itoa(unsigned int n)
{
	int		len;
	char	*result;

	len = ft_n_len(n);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (0);
	if (n == 0)
		result[0] = '0';
	while (n)
	{
		result[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}

static int	ft_n_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}
