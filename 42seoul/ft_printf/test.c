#include <stdio.h>
#include <stdarg.h>

void	str_print(const char *format, ...)
{
	va_list	ap;
	va_list	ap_cp;

	va_start(ap, format);
	printf("%d\n", va_arg(ap, int));
	printf("%d", va_arg(ap, int));
	printf("\n");

	va_end(ap);
}

int	main(void)
{
	str_print("dd", '0', 456);
	return (0);
}