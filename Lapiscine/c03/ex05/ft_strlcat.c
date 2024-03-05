unsigned int	check_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	new_len;

	i = 0;
	dest_len = check_len(dest);
	src_len = check_len(src);
	new_len = size - dest_len;
	if (size <= dest_len)
		return (src_len + size);
	while (i < new_len - 1 && src[i] && size != 0)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
