#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int cnt = 0;
	int	nb = 123;

	cnt = ft_printf("123 %d\n", nb);
	return (0);
}
