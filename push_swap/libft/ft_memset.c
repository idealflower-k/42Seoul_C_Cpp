#include "libft.h"

void	*ft_memset(void *d, int c, size_t len);

void	*ft_memset(void *d, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)d;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (temp);
}
