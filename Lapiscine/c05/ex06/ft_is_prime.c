int	ft_is_prime(int nb)
{
	long long int	i;

	i = 2;
	if (nb == 2)
		return (1);
	else if (nb < 2)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
