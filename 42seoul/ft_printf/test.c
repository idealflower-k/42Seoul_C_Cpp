#include <stdio.h>
#include <stdarg.h>

void	str_print(const char *format, ...)
{
	va_list	ap;
	va_list	ap_cp;

	va_start(ap, format);
	va_copy(ap_cp, ap);
	{
		printf("%s", va_arg(ap, char*));
		printf("%s", va_arg(ap, char*));
		printf("\n");
		printf("%s", va_arg(ap_cp, char*));
		printf("%s", va_arg(ap_cp, char*));
		printf("\n");
	}
	va_end(ap);
	va_end(ap_cp);
}

int main(void)
{
	str_print("dd", "hello", " friend");
	return (0);
}