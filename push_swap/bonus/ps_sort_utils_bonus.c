/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:17:20 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/05 14:31:14 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	*copy_stack(t_deque *stack, int *cp_stack)
{
	size_t	i;

	i = 0;
	while (i < stack->use_size)
	{
		cp_stack[i] = stack->nodes[i].data;
		i++;
	}
	return (cp_stack);
}

void	sort_copy(int *cp_stack, size_t size)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (cp_stack[i] > cp_stack[j])
			{
				tmp = cp_stack[i];
				cp_stack[i] = cp_stack[j];
				cp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	indexing_stack(int *cp_stack, t_deque *stack)
{
	size_t	idx;
	size_t	i;

	i = 0;
	idx = 0;
	while (i <= stack->rear)
	{
		idx = 0;
		while (stack->nodes[i].data != cp_stack[idx])
			idx++;
		stack->nodes[i].idx = idx;
		i++;
	}
	free(cp_stack);
}

void	put_lst(t_split *head, char **splited)
{
	int	num;
	int	i;

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
