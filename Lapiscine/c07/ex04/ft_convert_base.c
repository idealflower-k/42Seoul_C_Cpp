char	*change_to_base(int nb, char *base, int base_len);

int	check_base(char *base, int *count)
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
		*count += 1;
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

int	ft_atoi(char *str, char *base, int len)
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;
	int	from_len;
	int	to_len;

	from_len = 0;
	to_len = 0;
	if (check_base(base_from, &from_len))
	{
		nb = ft_atoi(nbr, base_from, from_len);
		if (check_base(base_to, &to_len))
			return (change_to_base(nb, base_to, to_len));
	}
	return (0);
}
