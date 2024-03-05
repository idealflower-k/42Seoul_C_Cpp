#include "philosophers.h"
#include "defines.h"
#include "parser.h"
#include "meta.h"
#include "dining.h"
#include "monitoring.h"
#include "utils.h"

int	main(int ac, char **av)
{
	t_meta	*meta;
	t_info	info;

	if (ac < 5 && ac < 6)
	{
		ft_print_err("arguments error\n");
		return (1);
	}
	meta = get_meta(ac, av);
	if (meta == NULL)
		return (1);
	if (!set_dining(&info))
	{
		free_all();
		return (1);
	}
	monitoring();
	destory_forks(meta->args->num_philo);
	destory_philos(meta->args->num_philo);
	free_all();
	free(meta);
	printf("=====end=====\n");
	return (0);
}
