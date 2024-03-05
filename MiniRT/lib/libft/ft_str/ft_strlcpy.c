#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const size_t	src_len = ft_strlen(src);
	size_t			i;

	i = 0;
	while (i < size - 1 && src[i] && size != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (src_len);
}
