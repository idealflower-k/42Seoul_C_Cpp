/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:21:40 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/25 20:04:00 by sanghwal         ###   ########.fr       */
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

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	base_len = ck_base(base);
	if (base_len == 0)
		return (0);
	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		else if (!((*str >= 9 && *str <= 13) || *str == 32
				|| *str == '+' || *str == '-'))
		{
			if (str_cmp(*str, base) != -1)
				res = (res * base_len) + str_cmp(*str, base);
			else if (str_cmp(*str, base) == -1)
				return (res * sign);
		}
		str++;
	}
	return (res * sign);
}
