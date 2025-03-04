#include "push_swap_bonus.h"

static void	pass_zero(const char *str, int *i);
static int	check_int(long result);

int	ft_atoi_ps(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	pass_zero(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result = sign * result;
	if (str[i] != 0)
		handle_error(1);
	return (check_int(result));
}

void	pass_zero(const char *str, int *i)
{
	if (!ft_isdigit(str[*i]))
		handle_error(1);
	while (str[*i] == '0')
		(*i)++;
}

int	check_int(long result)
{
	if (result > 2147483647 || result < -2147483648)
		handle_error(1);
	return ((int)result);
}
