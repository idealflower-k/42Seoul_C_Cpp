#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s = src;
	char		*tmp;
	size_t		i;

	if (!n || dest == src)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	tmp = dest;
	while (i < n)
	{
		tmp[i] = s[i];
		i++;
	}
	return (dest);
}
