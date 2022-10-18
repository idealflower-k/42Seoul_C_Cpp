/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:18:48 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/18 17:48:43 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

int	check_data(char **splited, t_deque *stack_a);

int	main(int ac, char *av[])
{
	t_deque	*stack_a;

	if (ac < 2)
		exit (1);
	data_split(ac, av);

}
// 숫자인지 아닌지 검사 && int형 범위 내의 숫자인지 검사
// 중복 검사

int	data_split(int ac, char **av)
{
	char	**splited;
	t_list	*head;
	int		i;
	int		cnt;


	head = ft_lstnew(0);
	if (!head)
		handle_error(1);
	cnt = 0;
	while (i < ac)
	{
		splited = ft_split(av[i], ' ');
		if (!splited)
			handle_error(1);
		save_splited(head, splited, &cnt);
	}
	move_stack(head, cnt);

}

void	save_splited(t_list **head, char **splited, int *cnt)
{
	int		i;
	t_list	*tmp;

	while (!splited[i])
	{
		tmp = ft_lstnew(&splited[i]);
		if (!tmp)
		{
			free_all(head, splited);
			handle_error(1);
		}
		ft_lstadd_back(head, tmp);
		cnt++;
	}
	free (splited);
}

void	move_stack(t_list **head, int cnt)
{
	t_deque	*stack_a;

	stack_a = dq_creat(cnt);
}

void	free_all(t_list **head, char **splited)
{
	t_list	*tmp;
	int		i;

	tmp = *head;
	while (tmp != 0)
	{
		free(tmp->content);
		tmp = tmp->next;
		free(tmp);
	}
	while (splited[i])
		free(splited[i++]);
	free(splited);
}

void	handle_error(int error)
{
	if (error == 1)
		write(1, "Error\n", 6);
	exit(1);
}