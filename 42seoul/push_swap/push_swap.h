/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:04:30 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/20 16:15:42 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_list
{
	long long	num;
	t_list		*next;
}	t_list;


typedef struct s_node
{
	int	data;
}	t_node;

typedef struct s_deque
{
	size_t	capacity;
	size_t	front;
	size_t	rear;
	t_node	*nodes;
}	t_deque;

#endif