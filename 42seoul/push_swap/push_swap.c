/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:17:13 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/25 16:02:50 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char *av[])
{
	t_split	*head;
	int		i;
	t_split	*tmp;

	if (ac < 2)
		exit(1);
	i = 1;
	head = 0;
	while (av[i] != 0)
	{
		head = split_num(av[i++], head);
	}
	tmp = head->next;
	while (tmp != 0)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
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
	put_lst(head, splited);

	return (head);
}

void	put_lst(t_split *head, char **splited)
{
	t_split	*node;
	int			num;
	int			i;

	num = 0;
	i = 0;
	while (splited[i])
	{
		num = ft_atoi_ps(splited[i++]);
		if (check_dup(head, num))
		{
			node = new_node(head, num);
		}
	}
}

t_split	*new_node(t_split *head, int num)
{
	t_split	*node;
	t_split	*tmp;

	tmp = head;
	node = (t_split *)malloc(sizeof(t_split));
	if (!node)
	{
		free_lst(head);
		handle_error(1);
	}
	node->num = num;
	node->next = 0;
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->next = node;
	return (node);
}

int	check_dup(t_split *head, int num)
{
	t_split	*tmp;

	tmp = head->next;
	while (tmp != 0)
	{
		if (tmp->num == num)
		{
			free_lst(head);
			handle_error(1);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	free_lst(t_split *head)
{
	t_split	*tmp;
	t_split	*del;

	tmp = head;
	while (tmp != 0)
	{
		del = tmp;
		if (tmp->next != 0)
			tmp = tmp->next;
		else
			break ;
		free(tmp);
	}
}

t_split	*lst_creat(void)
{
	t_split	*head;

	head = (t_split *)malloc(sizeof(t_split));
	if (!head)
		handle_error(1);
	head->num = 0;
	head->next = 0;
	return (head);
}

void	handle_error(int err)
{
	if (err == 1)
		write(1, "ERROR\n", 6);
	exit(1);
}