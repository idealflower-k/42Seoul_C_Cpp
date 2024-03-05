int	ft_isalnum(int c)
{
	if ((97 <= c && c <= 122) || (65 <= c && c <= 90) || (48 <= c && c <= 57))
		return (1);
	else
		return (0);
}
