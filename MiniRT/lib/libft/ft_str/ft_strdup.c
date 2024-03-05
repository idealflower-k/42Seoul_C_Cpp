#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*begin;
	char	*dest;
	size_t	i;

	dest = ft_malloc(sizeof(char) * (ft_strlen(s1) + 1));
	begin = dest;
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (begin);
}
