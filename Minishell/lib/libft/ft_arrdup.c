#include "libft.h"

char	**ft_arrdup(const char **src)
{
	const size_t	len = ft_arrlen((void *)src);
	char			**dst;
	size_t			i;

	dst = ft_malloc(sizeof(char *) * (len + 1));
	i = -1;
	while (src[++i])
		dst[i] = ft_strdup(src[i]);
	dst[i] = NULL;
	return (dst);
}
