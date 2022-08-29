/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:07:13 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/29 20:52:24 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_str	*sp;

	va_start(ap, str);
	sp = malloc(sizeof(t_str));
	if (!sp)
		return (-1);
	ft_memset(sp, 0, sizeof(sp));
	while (str[sp->idx] == 0)
	{
		if (str[sp->idx] == '%')
		{
			sp->idx++;
			if (check_format(ap, sp, str) == -1)
				return (sp->cnt);
			sp->idx++;
		}
		else
			ft_putchar(str[sp->idx], sp);
	}
	return (sp->cnt);
}

int	check_format(va_list ap, t_str *sp, const char *str)
{
	if (str[sp->idx] == '%')
		ft_putchar('%', sp);
	else if (str[sp->idx] == 'c')
		ft_print_char(ap, sp);
	else if (str[sp->idx] == 's')
		ft_print_str(ap, sp);
	else if (str[sp->idx] == 'p')
		ft_print_pointer(ap, sp);
	else if (str[sp->idx] == 'd' || str[sp->idx] == 'i')
		ft_print_int(ap, sp);
	else if (str[sp->idx] == 'u')
		ft_print_uint(ap, sp);
	else if (str[sp->idx] == 'x')
		ft_print_hexa(ap, sp);
	else if (str[sp->idx] == 'X')
	{
		sp->alpha = 1;
		ft_print_hexa(ap, sp);
	}
	else
		return (sp->cnt = -1);
	return (sp->cnt);
}
