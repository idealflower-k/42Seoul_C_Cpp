char	*ft_strrchr(const char *s, int c)
{
	const char	*str = s;

	while (*s++)
		;
	while (s != str)
	{
		s--;
		if (*s == (char)c)
			return ((char *)s);
	}
	return ((void *)0);
}
