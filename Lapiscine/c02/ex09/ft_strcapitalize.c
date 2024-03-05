void	set_low_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

void	check_alpha(int i, char *str)
{
	if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	else if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	set_low_alpha(str);
	check_alpha(0, str);
	while (str[i])
	{
		if (str[i] < '0' || (str[i] > '9' && str[i] < 'A')
			|| (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			check_alpha(i + 1, str);
		i++;
	}
	return (str);
}
