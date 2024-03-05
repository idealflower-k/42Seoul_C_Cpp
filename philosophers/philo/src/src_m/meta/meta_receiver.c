#include "philosophers.h"
#include "defines.h"
#include "meta.h"

void	*meta_receiver(t_meta_flag flag, int ac, char **av)
{
	t_meta	*meta;

	meta = singleton(ac, av);
	if (flag == META)
		return (meta);
	if (flag == META_ARG)
		return (meta->args);
	if (flag == META_FORKS)
		return (meta->forks);
	if (flag == META_PHILOS)
		return (meta->philos);
	return (NULL);
}
