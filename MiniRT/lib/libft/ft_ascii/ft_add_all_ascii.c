#include "libft.h"

int	ft_add_all_ascii(const char *str)
{
	int	sum;
	int	i;

	if (str == NULL)
		return (-1);
	sum = 0;
	i = -1;
	while (str[++i])
		sum += str[i];
	return (sum);
}
