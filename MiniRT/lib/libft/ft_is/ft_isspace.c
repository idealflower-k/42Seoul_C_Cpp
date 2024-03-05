int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}
