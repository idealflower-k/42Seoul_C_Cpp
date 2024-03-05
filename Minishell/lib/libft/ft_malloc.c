#include "libft.h"

void	*ft_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (!result)
		exit(EXIT_FAILURE);
	return (result);
}
