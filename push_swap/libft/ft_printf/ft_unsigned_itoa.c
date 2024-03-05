#include "ft_printf.h"

static int	ft_n_len(unsigned int n);

char	*ft_unsigned_itoa(unsigned int n)
{
	int		len;
	char	*result;

	len = ft_n_len(n);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (0);
	if (n == 0)
		result[0] = '0';
	while (n)
	{
		result[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}

static int	ft_n_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}
