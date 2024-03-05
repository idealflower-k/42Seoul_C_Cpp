#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	val;

	str = b;
	val = (unsigned char)c;
	while (len-- > 0)
		*str++ = val;
	return (b);
}
