/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:20:18 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/12 17:13:54 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_size(unsigned int num, int base_len, int *size)
{
	if (num >= (unsigned int)base_len)
	{
		ft_size(num / base_len, base_len, size);
		ft_size(num % base_len, base_len, size);
	}
	else
		*size += 1;
}

char	*change_to_base(int nb, char *base, int base_len)
{
	char			*result;
	unsigned int	num;
	int				size;

	size = 0;
	if (nb < 0)
	{
		num = nb * -1;
		size += 1;
	}
	else
		num = nb;
	ft_size(num, base_len, &size);
	result = (char *)malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	if (nb < 0)
		result[0] = '-';
	result[size] = 0;
	while ((nb >= 0 && size) || (nb < 0 && size > 1))
	{
		result[--size] = base[num % base_len];
		num /= base_len;
	}
	return (result);
}
