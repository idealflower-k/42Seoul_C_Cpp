#include "libft.h"

static size_t	define_diff(size_t s_len, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;
	size_t	diff;

	if (!s)
		return ((void *)0);
	s_len = ft_strlen(s);
	diff = define_diff(s_len, start, len);
	str = ft_malloc(sizeof(char) * (diff));
	i = 0;
	while (i < len && i + start < s_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	define_diff(size_t s_len, unsigned int start, size_t len)
{
	size_t	diff;

	if (s_len > start)
		diff = s_len - start + 1;
	else
		return (1);
	if (diff > len)
		diff = len + 1;
	else if (diff > s_len)
		diff = s_len + 1;
	return (diff);
}
