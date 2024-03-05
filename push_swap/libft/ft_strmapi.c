#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_idx;
	size_t	s_len;
	char	*result;

	if (!s || !f)
		return (0);
	s_len = ft_strlen(s);
	result = ft_calloc(s_len + 1, sizeof(char));
	if (!result)
		return (0);
	s_idx = 0;
	while (s_idx < s_len)
	{
		result[s_idx] = f(s_idx, s[s_idx]);
		s_idx++;
	}
	return (result);
}
