/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:23:45 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/29 16:21:01 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list ap, t_str *sp)
{
	char	*temp;
	int		i;

	temp = va_arg(ap, char *);
	i = 0;
	if (temp[0] == 0)
		ft_putchar(0, sp);
	else
		ft_putstr(temp, sp);
	sp->idx++;
	return (sp->cnt);
}

int	ft_putstr(const char *str, t_str *sp)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_putchar(str[i], sp) == -1)
			return (sp->cnt = -1);
		i++;
	}
	return (sp->cnt);
}
