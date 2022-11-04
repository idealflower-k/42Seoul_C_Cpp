/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:17:13 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/05 00:25:19 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	do_push_swap(stack_a);
	system("leaks push_swap");
	return (0);
}

void	do_push_swap(t_deque *stack_a)
{
	t_deque	*stack_b;
	int		*cp_stack;

	stack_b = deque_creat(stack_a->capacity);
	cp_stack = 0;
	cp_stack = (int *)malloc(sizeof(int) * stack_a->capacity);
	if (!stack_b || !cp_stack)
		handle_error(1);
	sort_copy(copy_stack(stack_a, cp_stack), stack_a->capacity);
	indexing_stack(cp_stack, stack_a);
	free(cp_stack);
	if (check_sort(stack_a))
		exit(0);
	write_oper(do_sort(stack_a, stack_b));
}

t_split	*split_num(char *av, t_split *head)
{
	char	**splited;

	if (!head)
		head = lst_creat();
	splited = ft_split(av, ' ');
	if (!splited || splited[0] == 0)
		handle_error(1);
	put_lst(head, splited);
	free_split(splited);
	return (head);
}

void	free_split(char **splited)
{
	size_t	i;

	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
	return ;
}

void	write_oper(t_oper *op_lst)
{
	t_oper	*tmp;

	tmp = op_lst->next;
	while (tmp != 0)
	{
		ft_printf("%s\n", tmp->op);
		tmp = tmp->next;
	}
	free_lst(op_lst);
}

void	free_lst(t_oper *op_lst)
{
	t_oper	*tmp;
	t_oper	*del;

	del = op_lst;
	while (del != 0)
	{
		tmp = del->next;
		free(del);
		del = tmp;
	}
}
