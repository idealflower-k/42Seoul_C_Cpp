#include "libft.h"


double	ft_random_double(void)
{
	return (ft_rand() / (FT_RAND_MAX + 1.0));
}


double	ft_random_double_range(const double min, const double max)
{
	return (min + (max - min) * ft_random_double());
}


int	ft_random_int_range(const int min, const int max)
{
	return (min + ft_rand() % (max - min));
}
