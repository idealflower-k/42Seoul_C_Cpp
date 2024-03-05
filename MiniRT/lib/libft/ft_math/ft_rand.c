#include "libft.h"

static inline unsigned long	_ft_lcg(t_accessor mode, unsigned long val)
{
	static unsigned long	next = 1;

	if (mode == GET)
	{
		next = next * 1103515245 + 12345;
		return ((int)(next / 65536) % FT_RAND_MAX);
	}
	if (mode == SET)
		next = val;
	return (0);
}

int	ft_rand(void)
{
	return (_ft_lcg(GET, 0));
}

void	ft_srand(unsigned long seed)
{
	_ft_lcg(SET, seed);
}
