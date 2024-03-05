#include "push_swap_bonus.h"

void	op_rra(t_deque *stack_a)
{
	if (stack_a->use_size >= 2)
		dq_push_front(stack_a, dq_pop_rear(stack_a));
	return ;
}

void	op_rrb(t_deque *stack_b)
{
	if (stack_b->use_size >= 2)
		dq_push_front(stack_b, dq_pop_rear(stack_b));
	return ;
}

void	op_rrr(t_deque *stack_a, t_deque *stack_b)
{
	op_rra(stack_a);
	op_rrb(stack_b);
	return ;
}
