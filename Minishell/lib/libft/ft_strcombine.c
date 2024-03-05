#include "libft.h"

char	*ft_strcombine(int n, ...)
{
	va_list	ap;	
	char	*tmp;
	char	*arg;
	char	*str;
	int		i;

	va_start(ap, n);
	i = 0;
	str = va_arg(ap, char *);
	while (i < n - 1)
	{
		arg = va_arg(ap, char *);
		tmp = str;
		str = ft_strjoin(str, arg);
		if (i != 0)
			free(tmp);
		i++;
	}
	va_end(ap);
	return (str);
}
