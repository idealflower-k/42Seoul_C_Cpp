#include "push_swap.h"

void	handle_error(int err)
{
	if (err == 1)
		write(2, "Error\n", 6);
	exit(1);
}
