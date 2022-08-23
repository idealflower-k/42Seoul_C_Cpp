/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:23:45 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/23 17:31:10 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(va_list ap, t_str *sp)
{
	char	*temp;
	int		i;

	temp = va_arg(ap, char *);
	i = 0;
	if (temp[i] == 0)
		ft_putchar(0, sp);
	while (temp[i] != 0 && temp[i])
	{
		if (ft_putchar(temp[i], sp) == -1)
			return (-1);
		i++;
	}
	return (0);
}
