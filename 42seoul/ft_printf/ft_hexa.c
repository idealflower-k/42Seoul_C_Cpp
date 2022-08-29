/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:28:08 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/29 16:58:02 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_print_pointer(va_list ap, t_str *sp)
{
	void	*temp;
	char	*hexa_str;

	temp = (void *)va_arg(ap, void *);
	hexa_str = change_to_hexa(temp);
	ft_putstr(hexa_str, sp);
	free(hexa_str);
	return (sp->cnt);
}

void	ft_size(int nb, const int base_len, int *size)
{
	if (nb >= base_len)
	{
		ft_size(nb / base_len, base_len, size);
		ft_size(nb % base_len, base_len, size);
	}
	else
		*size += 1;
}

char	*change_to_hexa(int nb)
{
	char			*result;
	int				size;
	const char		*base = "0123456789abcdef";
	const int		base_len = 16;

	size = 0;
	ft_size(nb, base_len, &size);
	result = (char *)malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	result[size] = 0;
	while (nb >= 0 && size)
	{
		result[--size] = base[nb % base_len];
		nb /= base_len;
	}
	return (result);
}
