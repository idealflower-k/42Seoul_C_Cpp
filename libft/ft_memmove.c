#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*temp;
	unsigned const char	*s;

	if (dst == src)
		return (dst);
	if (dst <= src)
	{
		temp = (unsigned char *)dst;
		s = (unsigned const char *)src;
		while (len--)
		{
			*temp++ = *s++;
		}
	}
	else
	{
		temp = (unsigned char *)dst;
		temp += len;
		s = (unsigned const char *)src + len;
		while (len--)
		{
			*--temp = *--s;
		}
	}
	return (dst);
}
