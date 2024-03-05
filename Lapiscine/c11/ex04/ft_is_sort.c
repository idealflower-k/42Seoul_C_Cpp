int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	temp;
	int	diff;

	i = 0;
	diff = 0;
	while (i < length - 1)
	{
		temp = f(tab[i], tab[i + 1]);
		if (temp == 0)
		{
			i++;
			continue ;
		}
		if (diff == 0)
			diff = temp;
		if ((diff > 0 && temp < 0) || (diff < 0 && temp > 0))
			return (0);
		i++;
	}
	return (1);
}
