#ifndef FT_MATH_H
# define FT_MATH_H

# include "libft_include.h"

int		ft_find_next_prime(int nb);
int		ft_find_prev_prime(int nb);
int		ft_rand(void);
void	ft_srand(unsigned long seed);
double	ft_random_double(void);
double	ft_random_double_range(const double min, const double max);
int		ft_random_int_range(const int min, const int max);

#endif