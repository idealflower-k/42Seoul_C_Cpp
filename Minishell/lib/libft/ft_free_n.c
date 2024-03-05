#include "libft.h"

void	ft_free_n(int n, ...)
{
	va_list	ap;
	void	*target;
	int		i;

	va_start(ap, n);
	i = 0;
	while (i < n)
	{
		target = va_arg(ap, void *);
		free(target);
		i++;
	}
	va_end(ap);
}
