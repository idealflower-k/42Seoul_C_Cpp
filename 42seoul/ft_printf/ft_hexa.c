/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:28:08 by sanghwal          #+#    #+#             */
/*   Updated: 2022/09/06 18:12:18 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(va_list *ap, t_str *sp)
{
	void	*temp;
	char	*hexa_str;

	temp = (void *)va_arg(*ap, void *);
	hexa_str = change_to_hexa((unsigned long long)temp);
	if (!hexa_str)
		sp->cnt = -1;
	else
	{
		if (write(1, "0x", 2) == -1)
			sp->cnt = -1;
		else
			sp->cnt += 2;
		if (sp->cnt != -1)
			ft_putstr(hexa_str, sp);
		free(hexa_str);
	}
	return (sp->cnt);
}

int	ft_print_hexa(va_list *ap, t_str *sp)
{
	unsigned int	nb;
	char			*temp;
	int				i;

	i = 0;
	nb = va_arg(*ap, unsigned int);
	temp = change_to_hexa(nb);
	if (!temp)
		return (sp->cnt = -1);
	else if (sp->alpha == 1)
	{
		while (temp[i])
		{
			if (ft_isalpha(temp[i]))
				temp[i] = ft_toupper(temp[i]);
			i++;
		}
	}
	ft_putstr(temp, sp);
	free(temp);
	return (sp->cnt);
}

void	ft_size(unsigned long long nb, unsigned int base_len, int *size)
{
	if (nb >= base_len)
	{
		ft_size(nb / base_len, base_len, size);
		ft_size(nb % base_len, base_len, size);
	}
	else
		*size += 1;
	return ;
}

char	*change_to_hexa(unsigned long long nb)
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
