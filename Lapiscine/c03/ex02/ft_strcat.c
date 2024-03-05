char	*ft_strcat(char *dest, char *src)
{
	int	dest_end;
	int	src_idx;
	int	dest_idx;

	dest_end = 0;
	src_idx = 0;
	while (dest[dest_end])
		dest_end++;
	dest_idx = dest_end;
	while (src[src_idx])
		dest[dest_idx++] = src[src_idx++];
	dest[dest_idx] = 0;
	return (dest);
}
