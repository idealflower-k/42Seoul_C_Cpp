/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:04:30 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/30 17:33:21 by sanghwal         ###   ########seoul.kr  */
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
	size_t	data;
}	t_node;

typedef struct s_deque
{
	size_t	capacity;
	size_t	front;
	size_t	rear;
	size_t	use_size;
	t_node	*nodes;
}	t_deque;

typedef struct s_oper
{
	char			*op;
	struct s_oper	*next;
}	t_oper;

t_split	*split_num(char *av, t_split *head);
t_split	*lst_creat(void);
t_deque	*stack_a_creat(t_deque *stack_a, t_split *head);
t_deque	*deque_creat(size_t size);
t_oper	*add_op(t_oper *op_lst, char *op);
t_oper	*do_sort(t_deque *stack_a, t_deque *stack_b);
size_t	dq_pop_front(t_deque *stack);
size_t	dq_pop_rear(t_deque *stack);
size_t	set_chunk(size_t capacity);
void	dq_push_front(t_deque *stack, size_t num);
void	dq_push_rear(t_deque *stack, size_t num);
void	new_node(t_split *head, int num);
void	put_lst(t_split *head, char **splited);
void	fill_stack_a(t_deque *stack_a, t_split *head);
void	handle_error(int err);
void	sorting(t_deque *stack_a);
void	op_sa(t_deque *stack_a, t_oper *op_lst, int flag);
void	op_sb(t_deque *stack_b, t_oper *op_lst, int flag);
void	op_ss(t_deque *stack_a, t_deque *stack_b, t_oper *op_lst);
void	op_pa(t_deque *stack_a, t_deque *stack_b, t_oper *op_lst);
void	op_pb(t_deque *stack_a, t_deque *stack_b, t_oper *op_lst);
void	op_ra(t_deque *stack_a, t_oper *op_lst, int flag);
void	op_rb(t_deque *stack_b, t_oper *op_lst, int flag);
void	op_rr(t_deque *stack_a, t_deque *stack_b, t_oper *op_lst);
void	op_rra(t_deque *stack_a, t_oper *op_lst, int flag);
void	op_rrb(t_deque *stack_b, t_oper *op_lst, int flag);
void	op_rrr(t_deque *stack_a, t_deque *stack_b, t_oper *op_lst);
void	indexing_stack(int *cp_stack, t_deque *stack);
void	sort_copy(int *cp_stack);
int		*copy_stack(t_deque *stack, int *cp_stack);
int		ft_atoi_ps(const char *str);
int		check_overlap(t_split *head, int num);
void	make_sorted_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
size_t	get_front(t_deque *stack);
void	make_hourglass_utils(t_deque *s_a, t_deque *s_b, \
	t_oper *op_lst, size_t i);
void	make_hourglass(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
void	hourglass_sort(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
size_t	set_chunk(size_t capacity);

void	b_rr(t_deque *deque_b, size_t *position, size_t *top_num, t_oper *op_lst);
void	b_r(t_deque *deque_b, size_t *position, size_t *top_num, t_oper *op_lst);
void	find_big_idx(t_node *node, size_t *size, size_t *big_idx);
void	b_to_a(t_deque *deque_a, t_deque *deque_b, t_oper *op_lst);

void	write_oper(t_oper *op_lst);
void	show_stack(t_deque *stack_a, t_deque *stack_b);
void	show_idx(t_deque *stack, int *cp_stack);
#endif