#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;

	temp = 0;
	while (*s)
	{
		if ((char)c == *s)
			temp = s;
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return ((char *)temp);
}
