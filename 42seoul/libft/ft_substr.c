
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	size_t i;
	size_t j;

	j = 0;
	i = start;
	if (s == 0 || ft_strlen(s) + 1 <= start)
		return (0);
	substr = malloc(sizeof(s) * (len + 1));
	if (substr == 0)
		return (0);
	while(s[i] && j < len && len > 0)
	{
		if (j < len)
			substr[j] = s[i];
		j++;
		i++;
	}
	substr[j] = 0;
	return (substr);
}
