int	ft_isalnum(int c)
{
	if (('0' <= c && c <= '9') || \
		('A' <= c && c <= 'Z') || \
		('a' <= c && c <= 'z'))
		return (1);
	else
		return (0);
}
