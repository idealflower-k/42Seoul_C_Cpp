#include "ft_printf.h"

int	ft_print_char(va_list *ap, t_str *sp)
{
	char	temp;

	temp = (char)va_arg(*ap, int);
	ft_putchar(temp, sp);
	return (sp->cnt);
}

int	ft_putchar(char c, t_str *sp)
{
	if (write(1, &c, 1) == -1)
		return (sp->cnt = -1);
	sp->cnt++;
	return (sp->cnt);
}
