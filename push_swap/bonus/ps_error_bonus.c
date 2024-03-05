#include "push_swap_bonus.h"

void	handle_error(int err)
{
	if (err == 1)
		write(2, "Error\n", 6);
	exit(1);
}
