#include "philosophers.h"
#include "defines.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

void	ft_print_err(const char *str)
{
	printf("%s", str);
}
