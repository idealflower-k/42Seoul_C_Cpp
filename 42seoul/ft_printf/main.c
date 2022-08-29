#include <unistd.h>
#include "ft_printf.h"

int main(void)
{
	char c = '1';
	write(1, &c, 1);
	ft_printf("%c", c);
	return (0);
}