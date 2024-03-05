#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*s;
	size_t				idx;

	idx = 0;
	temp = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (dst == src)
		return (dst);
	while (idx < n)
	{
		temp[idx] = s[idx];
		idx++;
	}
	return (dst);
}
