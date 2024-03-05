#include <unistd.h>

void	ft_putchar(int c)
{
	c = c + '0';
	write(1, &c, 1);
}
