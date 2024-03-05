#include "push_swap.h"

void	op_ra(t_deque *stack_a, t_oper *op_lst, int flag)
{
	if (stack_a->use_size >= 2)
		dq_push_rear(stack_a, dq_pop_front(stack_a));
	if (flag == 1 && op_lst != 0)
		add_op(op_lst, "ra");
	return ;
}

void	op_rb(t_deque *stack_b, t_oper *op_lst, int flag)
{
	if (stack_b->use_size >= 2)
		dq_push_rear(stack_b, dq_pop_front(stack_b));
	if (flag == 1 && op_lst != 0)
		add_op(op_lst, "rb");
	return ;
}

void	op_rr(t_deque *stack_a, t_deque *stack_b, t_oper *op_lst)
{
	op_ra(stack_a, op_lst, 0);
	op_rb(stack_b, op_lst, 0);
	if (op_lst != 0)
		add_op(op_lst, "rr");
	return ;
}
