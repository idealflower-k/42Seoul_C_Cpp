int	check_base2(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == 0 || base[1] == 0)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+' || (base[i] >= 9 && base[i] <= 13)
			|| base[i] == 32)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	myatoi(char *str, char *base, int len)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (check_in_base(str[i], base) != -1)
	{
		result = (result * len) + check_in_base(str[i], base);
		i++;
	}
	return (sign * result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (base[len])
		len++;
	if (check_base2(base) == 0)
		return (0);
	return (myatoi(str, base, len));
}
