/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:17:13 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/30 16:26:57 by sanghwal         ###   ########seoul.kr  */
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
		handle_error(1);
	fill_stack_a(stack_a, head);
	sorting(stack_a);
	exit(0);
}

t_split	*split_num(char *av, t_split *head)
{
	char	**splited;

	if (!head)
		head = lst_creat();
	splited = ft_split(av, ' ');
	if (!splited)
		handle_error(1);
	put_lst(head, splited);
	return (head);
}

void	put_lst(t_split *head, char **splited)
{
	int		num;
	int		i;

	num = 0;
	i = 0;
	while (splited[i])
	{
		num = ft_atoi_ps(splited[i++]);
		if (check_overlap(head, num))
		{
			new_node(head, num);
			head->len++;
		}
	}
}
