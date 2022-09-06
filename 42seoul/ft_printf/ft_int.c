/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:08:50 by sanghwal          #+#    #+#             */
/*   Updated: 2022/09/06 17:11:31 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list *ap, t_str *sp)
{
	char	*temp;
	int		nb;

	nb = va_arg(*ap, int);
	temp = ft_itoa(nb);
	if (!temp)
		return (sp->cnt = -1);
	ft_putstr(temp, sp);
	free(temp);
	return (sp->cnt);
}

int	ft_print_uint(va_list *ap, t_str *sp)
{
	unsigned int	nb;
	char			*temp;

	nb = va_arg(*ap, unsigned int);
	temp = ft_unsigned_itoa(nb);
	if (!temp)
		return (sp->cnt = -1);
	ft_putstr(temp, sp);
	free(temp);
	temp = 0;
	return (sp->cnt);
}
