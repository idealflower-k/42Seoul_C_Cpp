/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:53:30 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/29 20:02:40 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list ap, t_str *sp)
{
	char	temp;

	temp = va_arg(ap, int);
	ft_putchar(temp, sp);
	sp->idx++;
	return (sp->cnt);
}

int	ft_putchar(char c, t_str *sp)
{
	if (write(1, &c, 1) == -1)
		return (sp->cnt = -1);
	sp->cnt++;
	return (sp->cnt);
}
