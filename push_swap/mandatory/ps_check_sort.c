#include "push_swap.h"

int	check_sort(t_deque *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->use_size)
	{
		if (i == stack->nodes[(stack->front + i) % stack->capacity].idx)
			i++;
		else
			return (0);
	}
	return (1);
}
