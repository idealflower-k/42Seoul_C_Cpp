int	ft_prime(int nb)
{
	long long int	i;

	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!(ft_prime(nb)))
		nb++;
	return (nb);
}
