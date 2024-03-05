#include "libft.h"

t_bool	is_prime(int nb)
{
	int	i;

	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (FT_FALSE);
		i++;
	}
	return (FT_TRUE);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (is_prime(nb))
		nb++;
	while (!is_prime(nb))
		nb++;
	return (nb);
}
