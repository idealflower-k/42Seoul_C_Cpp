void	swap_int(int i, int j, int *tab)
{
	int	temp;

	temp = 0;
	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j <= size / 2)
	{
		swap_int(i, size - j, tab);
		i++;
		j++;
	}
}
