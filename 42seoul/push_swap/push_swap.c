/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:17:13 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/25 19:19:52 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_split	*head;
	t_deque	*stack_a;
	int		i;

	if (ac < 2)
		exit(1);
	i = 1;
	head = 0;
	while (av[i] != 0)
		head = split_num(av[i++], head);
	stack_a = deque_creat(head->len);
	if (!stack_a)
	{
		free_lst(head);
		handle_error(1);
	}
	fill_stack_a(stack_a, head);
	merge_sort(stack_a);
	free_lst(head);
	return (0);
}

t_split	*split_num(char *av, t_split *head)
{
	char	**splited;
	int		i;

	if (!head)
		head = lst_creat();
	i = 1;
	splited = ft_split(av, ' ');
	if (!splited)
	{
		free_lst(head);
		handle_error(1);
	}
	put_lst(head, splited);
	return (head);
}

void	put_lst(t_split *head, char **splited)
{
	t_split	*node;
	int		num;
	int		i;

	num = 0;
	i = 0;
	while (splited[i])
	{
		num = ft_atoi_ps(splited[i++]);
		if (check_dup(head, num))
		{
			node = new_node(head, num);
			head->len++;
		}
	}
}
