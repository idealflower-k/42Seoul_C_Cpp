#include <stdio.h>
#include <stdarg.h>

void	str_print(const char *format, ...)
{
	va_list	ap;
	va_list	ap_cp;
	unsigned int	temp;

	va_start(ap, format);
	printf("%x\n", va_arg(ap, int));
	temp = va_arg(ap, int);
	printf("%X\n", temp);
	va_end(ap);
}

int	main(void)
{
	long	nb = -1;

	str_print("dd", 0, nb);
	return (0);
}
