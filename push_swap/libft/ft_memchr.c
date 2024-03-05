#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	value;
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)s;
	value = (unsigned char)c;
	while (i < n)
	{
		if (temp[i] == value)
			return ((void *)temp + i);
		i++;
	}
	return ((void *)0);
}
