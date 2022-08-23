/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:53:30 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/23 17:21:48 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap, t_str *sp)
{
	char	temp;

	temp = va_arg(ap, int);
	if (ft_putchar(temp, sp) == -1)
		return (-1);
	return (0);
}

int	ft_putchar(char c, t_str *sp)
{
	if (write(1, c, 1) == -1)
		return (-1);
	sp->cnt++;
	return (0);
}
