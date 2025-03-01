#include "ft_printf.h"

int	ft_print_str(va_list *ap, t_str *sp)
{
	char	*temp;

	temp = va_arg(*ap, char *);
	if (!temp)
		ft_putstr("(null)", sp);
	else
		ft_putstr(temp, sp);
	return (sp->cnt);
}

int	ft_putstr(const char *str, t_str *sp)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_putchar(str[i], sp) == -1)
			return (sp->cnt = -1);
		i++;
	}
	return (sp->cnt);
}
