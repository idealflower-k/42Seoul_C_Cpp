#include "libft.h"

int	ft_arrlen(void **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return (0);
	while (arr[i])
		i++;
	return (i);
}
