#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_str	*sp;
	int		cnt;

	cnt = 0;
	va_start(ap, str);
	sp = malloc(sizeof(t_str));
	if (!sp)
		return (-1);
	ft_memset(sp, 0, sizeof(sp));
	while (str[sp->idx] != 0 && sp->cnt != -1)
	{
		if (str[sp->idx] == '%')
		{
			sp->idx++;
			check_format(&ap, sp, str);
		}
		else
			ft_putchar(str[sp->idx], sp);
		sp->idx++;
	}
	cnt = sp->cnt;
	free(sp);
	return (cnt);
}

int	check_format(va_list *ap, t_str *sp, const char *str)
{
	if (str[sp->idx] == '%')
		ft_putchar('%', sp);
	else if (str[sp->idx] == 'c')
		ft_print_char(ap, sp);
	else if (str[sp->idx] == 's')
		ft_print_str(ap, sp);
	else if (str[sp->idx] == 'p')
		ft_print_pointer(ap, sp);
	else if (str[sp->idx] == 'd' || str[sp->idx] == 'i')
		ft_print_int(ap, sp);
	else if (str[sp->idx] == 'u')
		ft_print_uint(ap, sp);
	else if (str[sp->idx] == 'x')
	{
		sp->alpha = 0;
		ft_print_hexa(ap, sp);
	}
	else if (str[sp->idx] == 'X')
	{
		sp->alpha = 1;
		ft_print_hexa(ap, sp);
	}
	else
		return (sp->cnt = -1);
	return (sp->cnt);
}
