/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:04:30 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/01 19:57:53 by sanghwal         ###   ########seoul.kr  */
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
void	do_push_swap(t_deque *stack_a);
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
void	indexing_stack(size_t *cp_stack, t_deque *stack);
void	sort_copy(size_t *cp_stack, size_t size);
size_t	*copy_stack(t_deque *stack, size_t *cp_stack);
int		ft_atoi_ps(const char *str);
int		check_overlap(t_split *head, int num);
void	make_sorted_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
size_t	most_big(t_deque *stack);
void	push_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst, size_t big_idx);
size_t	get_front(t_deque *stack);
void	make_hourglass_utl(t_deque *s_a, t_deque *s_b, \
	t_oper *op_lst, size_t i);
void	make_hourglass(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
void	hourglass_sort(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
size_t	set_chunk(size_t capacity);
void	check_rra(t_deque *s_a, t_oper *op_lst, size_t ichunk);
size_t	get_rear(t_deque *stack);
size_t	comp_idx(size_t big, size_t n_big, t_deque *stack);
size_t	comp_idx2(size_t big, size_t n_big, t_deque *stack);
size_t	next_big(t_deque *stack);
size_t	find_big(t_deque *stack);
void	check_sort(t_deque *stack);
void	small_sort(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
void	sort_two(t_deque *s_a, t_oper *op_lst);
void	sort_three(t_deque *s_a, t_oper *op_lst, size_t num);
void	sort_four(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
void	sort_five(t_deque *s_a, t_deque *s_b, t_oper *op_lst);

void	write_oper(t_oper *op_lst);
void	show_stack(t_deque *stack_a, t_deque *stack_b);
void	show_idx(t_deque *stack, size_t *cp_stack);
#endif