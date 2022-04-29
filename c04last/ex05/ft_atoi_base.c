/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:21:40 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/29 22:12:06 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ck_base(char *base)
{
	int	len;

	len = 0;
	while (base[len])
	{
		len++;
		if ((base[len] >= 9 && base[len] <= 13) || base[len] == 32
			|| base[len] == '-' || base[len] == '+')
			return (0);
	}
	return (len);
}

int	str_cmp(char word, char*base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (word == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_char(char str)
{
	if ((str >= 9 && str <= 13) || str == 32
		|| str == '+' || str == '-')
		return (0);
	else
		return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	base_len = ck_base(base);
	while (*str && base_len != 0)
	{
		if (*str == '-')
			sign *= -1;
		else if (check_char(*str) == 1)
		{
			while (str_cmp(*str, base) != -1)
			{
				res = (res * base_len) + str_cmp(*str, base);
				str++;
			}
			return (res * sign);
		}
		str++;
	}
	return (0);
}
