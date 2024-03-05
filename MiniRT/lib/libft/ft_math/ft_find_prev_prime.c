#include "libft.h"

bool	is_prime(int nb)
{
	int	i;

	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (false);
		i++;
	}
	return (true);
}

int	ft_find_prev_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (is_prime(nb))
		nb--;
	while (!is_prime(nb))
		nb--;
	return (nb);
}
