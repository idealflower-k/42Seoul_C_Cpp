int	ft_strlen(char *str)
{
	int	str_c;

	str_c = 0;
	while (str[str_c])
	{
		str_c++;
	}
	return (str_c);
}
