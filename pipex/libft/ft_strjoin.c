#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!temp)
		return (0);
	ft_strlcat(temp, (char *)s1, s1_len + 1);
	ft_strlcat(temp, (char *)s2, s1_len + s2_len + 1);
	return (temp);
}
