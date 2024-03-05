#include "libft.h"

char	*ft_remove_suffix(const char *origin)
{
	const size_t	origin_len = ft_strlen(origin);
	const size_t	suffix_len = ft_strlen(ft_strrchr(origin, '.'));

	return (ft_substr(origin, 0, origin_len - suffix_len));
}
