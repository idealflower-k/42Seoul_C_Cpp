#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*tmp;

	if (!dest && !src)
		return (NULL);
	if (dest <= src)
	{
		s = (const unsigned char *)src;
		tmp = (unsigned char *)dest;
		while (len--)
			*tmp++ = *s++;
	}
	else
	{
		tmp = (unsigned char *)dest;
		tmp += len;
		s = (const unsigned char *)src;
		s += len;
		while (len--)
			*--tmp = *--s;
	}
	return (dest);
}
