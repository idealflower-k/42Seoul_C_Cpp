#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (i < dstsize - 1 && src[i] && dstsize != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dest[i] = '\0';
	return (src_len);
}
