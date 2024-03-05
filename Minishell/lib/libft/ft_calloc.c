#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	dest = malloc(size * count);
	if (dest)
		ft_bzero(dest, (size * count));
	else
		return ((void *)0);
	return (dest);
}
