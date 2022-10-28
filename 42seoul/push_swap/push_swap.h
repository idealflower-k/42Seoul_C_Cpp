/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:04:30 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/28 18:03:29 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_split
{
	int				num;
	size_t			len;
	struct s_split	*next;
}	t_split;

typedef struct s_node
{
	int		data;
	size_t	idx;
}	t_node;

typedef struct s_deque
{
	size_t	capacity;
	size_t	front;
	size_t	rear;
	size_t	use_size;
	t_node	*nodes;
}	t_deque;

t_split	*split_num(char *av, t_split *head);
t_split	*new_node(t_split *head, int num);
t_split	*lst_creat(void);
t_deque	*stack_a_creat(t_deque *stack_a, t_split *head);
t_deque	*deque_creat(size_t size);
void	fill_stack_a(t_deque *stack_a, t_split *head);
void	put_lst(t_split *head, char **splited);
void	free_lst(t_split *head);
void	handle_error(int err);
void	sorting(t_deque *stack_a);
void	free_stack(t_deque *stack);
void	dq_push_front(t_deque *stack, int num);
void	dq_push_rear(t_deque *stack, int num);
void	op_sa(t_deque *stack_a);
void	op_sb(t_deque *stack_b);
void	op_ss(t_deque *stack_a, t_deque *stack_b);
void	op_pa(t_deque *stack_a, t_deque *stack_b);
void	op_pb(t_deque *stack_a, t_deque *stack_b);
void	op_ra(t_deque *stack_a);
void	op_rb(t_deque *stack_b);
void	op_rr(t_deque *stack_a, t_deque *stack_b);
void	op_rra(t_deque *stack_a);
void	op_rrb(t_deque *stack_b);
void	op_rrr(t_deque *stack_a, t_deque *stack_b);
void	indexing_stack(int *cp_stack, t_deque *stack);
void	sort_copy(int *cp_stack);
int		*copy_stack(t_deque *stack, int *cp_stack);
int		dq_pop_front(t_deque *stack);
int		dq_pop_rear(t_deque *stack);
int		ft_atoi_ps(const char *str);
int		check_dup(t_split *head, int num);


void	show_stack(t_deque *stack_a, t_deque *stack_b);
void	show_idx(t_deque *stack, int *cp_stack);
#endif