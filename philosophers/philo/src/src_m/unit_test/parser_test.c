#include "philosophers.h"
#include "defines.h"
#include "parser.h"

void	parser_test(t_meta *meta, int ac)
{
	printf("------ PARSER_TEST ------\n");
	printf("Number of philos : %d\n", meta->args->num_philo);
	printf("Time to DIE : %llu\n", meta->args->t_die);
	printf("Time to EAT : %llu\n", meta->args->t_eat);
	printf("Time to SLEEP : %llu\n", meta->args->t_sleep);
	if (ac == 6)
		printf("Must have to eat : %d\n", meta->args->must_eat);
	printf("------ END TEST ------\n");
	free(meta->args);
}
