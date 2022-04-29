/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:33:04 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/29 22:08:40 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	temp;

	temp = 0;
	sign = 1;
	while (*str)
	{
		if (*str == '-')
		{
			sign *= -1;
			str++;
		}
		else if (*str >= '0' && *str <= '9')
		{
			while (*str >= '0' && *str <= '9' && *str != 0)
			{
				temp = (temp * 10) + (*str - '0');
				str++;
			}
			return (sign * temp);
		}
		else
			str++;
	}
	return (0);
}
int main(int argc, char **argv)
{
	printf("%d", ft_atoi(argv[1]));
}
