#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	const size_t	dest_len = ft_strlen(dest);
	const size_t	src_len = ft_strlen(src);
	size_t			i;
	size_t			new_len;

	if (size <= dest_len)
		return (src_len + size);
	i = 0;
	new_len = size - dest_len;
	while (i < new_len - 1 && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
