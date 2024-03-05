#include "push_swap.h"

size_t	most_big(t_deque *stack)
{
	size_t	idx;
	size_t	big_idx;
	size_t	cnt;

	cnt = 0;
	idx = stack->front;
	big_idx = stack->use_size - 1;
	while (big_idx != stack->nodes[idx].idx)
	{
		if (idx == stack->capacity - 1)
			idx = 0;
		else
			idx++;
		cnt++;
	}
	return (cnt);
}

size_t	next_big(t_deque *stack)
{
	size_t	idx;
	size_t	big_idx;
	size_t	cnt;

	cnt = 0;
	idx = stack->front;
	big_idx = stack->use_size - 2;
	while (big_idx != stack->nodes[idx].idx)
	{
		if (idx == stack->capacity - 1)
			idx = 0;
		else
			idx++;
		cnt++;
	}
	return (cnt);
}

size_t	find_big(t_deque *stack)
{
	size_t	idx;
	size_t	big_idx;
	size_t	cnt;

	cnt = 0;
	idx = stack->front;
	big_idx = stack->use_size;
	while (big_idx != stack->nodes[idx].idx)
	{
		if (idx == stack->capacity - 1)
			idx = 0;
		else
			idx++;
		cnt++;
	}
	return (cnt);
}
