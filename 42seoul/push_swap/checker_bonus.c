/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:42:50 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/04 17:26:42 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char *av[])
{
	t_split	*head;
	t_deque	*stack_a;
	int		i;

	if (ac < 2)
		exit(0);
	i = 1;
	head = 0;
	while (av[i] != 0)
	{
		if (av[i][0] == '\0')
			handle_error(1);
		head = split_num(av[i++], head);
	}
	stack_a = deque_creat(head->len);
	if (!stack_a)
		handle_error(1);
	fill_stack_a(stack_a, head);
}

void	set_checker(t_deque *stack_a)
{
	t_deque	*stack_b;
	int		*cp_stack;

	stack_b = deque_creat(stack_a->capacity);
	cp_stack = (int *)malloc(sizeof(int) * stack_a->capacity);
	if (!stack_b || !cp_stack)
		handle_error(1);
	sort_copy(copy_stack(stack_a, cp_stack), stack_a->capacity);
	indexing_stack(cp_stack, stack_a);
}

void	checker(t_deque *s_a, t_deque *s_b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		do_op(s_a, s_b, cmd);
		cmd = get_next_line(0);
	}
	if (s_b->use_size == 0 && check_sort(s_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	do_op(t_deque *s_a, t_deque *s_b, char *cmd)
{
	ft_strncmp(cmp, "sa\n", 3)
	if (cmd == "sa\n")
		op_sa(s_a, 0, 0);
	else if (cmd == "sb\n")
		op_sb(s_b, 0, 0);
	else if (cmd == "ss\n")
		op_ss(s_a, s_b, 0);
	else if (cmd == "pa\n")
		op_pa(s_a, s_b, 0);
	else if (cmd == "pb\n")
		op_pb(s_a, s_b, 0);
	else if (cmd == "ra\n")
		op_ra(s_a, 0, 0);
	else if (cmd == "rb\n")
		op_rb(s_b, 0, 0);
	else if (cmd == "rr\n")
		op_rr(s_a, s_b, 0);
	else if (cmd == "rra\n")
		op_rra(s_a, 0, 0);
	else if (cmd == "rrb\n")
		op_rrb(s_b, 0, 0);
	else if (cmd == "rrr\n")
		op_rrr(s_a, s_b, 0);
	else
		handle_error(1);
}
