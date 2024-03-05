char	*ft_strcat(char *dest, char *src)
{
	char	*begin;

	begin = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (begin);
}
