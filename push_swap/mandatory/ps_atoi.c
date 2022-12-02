/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:28:30 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/10 22:28:46 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

static void	pass_zero(const char *str, int *i);
static int	check_int(long result);

int	ft_atoi_ps(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	pass_zero(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result = sign * result;
	if (str[i] != 0)
		handle_error(1);
	return (check_int(result));
}

void	pass_zero(const char *str, int *i)
{
	if (!ft_isdigit(str[*i]))
		handle_error(1);
	while (str[*i] == '0')
		(*i)++;
}

#include <stdio.h>

int	check_int(long result)
{
	if (result > 2147483647 || result < -2147483648)
		handle_error(1);
	return ((int)result);
}
