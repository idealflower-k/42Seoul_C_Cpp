#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*temp;

	temp = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	temp = ft_calloc((end - start) + 1, sizeof(char));
	if (!temp)
		return (0);
	ft_strlcpy(temp, &s1[start], (end - start) + 1);
	return (temp);
}
