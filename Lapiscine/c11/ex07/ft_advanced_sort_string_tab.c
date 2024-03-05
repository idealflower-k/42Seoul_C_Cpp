void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		len;
	int		j;
	char	*temp;

	len = 0;
	while (tab[len])
		len++;
	while (len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		len--;
	}
}
