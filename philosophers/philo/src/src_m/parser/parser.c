#include "philosophers.h"
#include "defines.h"
#include "utils.h"
#include "meta.h"

t_bool	set_number_of_philosophers(t_arg **args, char *av)
{
	int			num;
	uint64_t	unum;

	num = 0;
	if (!ft_atouint64(av, &unum))
	{
		free(*args);
		ft_print_err("number of philosophers error\n");
		return (FT_FALSE);
	}
	if (unum > 2147483647)
	{
		free(*args);
		ft_print_err("number of philosophers error\n");
		return (FT_FALSE);
	}
	num = (int)unum;
	(*args)->num_philo = num;
	return (FT_TRUE);
}

t_bool	set_times(t_arg **args, char **av)
{
	uint64_t	ft_time;
	int			i;
	int			idx;

	idx = 2;
	i = -1;
	ft_time = 0;
	while (++i < 3)
	{
		if (!ft_atouint64(av[idx++], &ft_time))
		{
			free(*args);
			ft_print_err("invalid time error\n");
			return (FT_FALSE);
		}
		if (i == 0)
			(*args)->t_die = ft_time;
		else if (i == 1)
			(*args)->t_eat = ft_time;
		else
			(*args)->t_sleep = ft_time;
		ft_time = 0;
	}
	return (FT_TRUE);
}

t_bool	set_must_eat(t_arg **args, char *av)
{
	int			num;
	uint64_t	unum;

	if (!ft_atouint64(av, &unum))
	{
		free(*args);
		ft_print_err("invalid must_eat error\n");
		return (FT_FALSE);
	}
	if (unum > 2147483647)
	{
		free(*args);
		ft_print_err("invalid must_eat error\n");
		return (FT_FALSE);
	}
	num = (int)unum;
	(*args)->must_eat = num;
	return (FT_TRUE);
}
