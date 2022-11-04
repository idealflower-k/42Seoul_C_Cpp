/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:46:30 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/04 20:42:46 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft.h"


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

typedef struct s_oper
{
	char			*op;
	struct s_oper	*next;
}	t_oper;

t_split	*split_num(char *av, t_split *head);
void	do_op(t_deque *s_a, t_deque *s_b, char *cmd);
void	checker(t_deque *s_a, t_deque *s_b);
void	set_checker(t_deque *stack_a);
t_split	*split_num(char *av, t_split *head);
t_split	*lst_creat(void);
t_deque	*stack_a_creat(t_deque *stack_a, t_split *head);
t_deque	*deque_creat(size_t size);
t_oper	*add_op(t_oper *op_lst, char *op);
t_oper	*do_sort(t_deque *stack_a, t_deque *stack_b);
size_t	dq_pop_front(t_deque *stack);
size_t	dq_pop_rear(t_deque *stack);
size_t	set_chunk(size_t capacity);
int		*copy_stack(t_deque *stack, int *cp_stack);
size_t	most_big(t_deque *stack);
size_t	get_front(t_deque *stack);
size_t	get_rear(t_deque *stack);
size_t	comp_idx(size_t big, size_t n_big, t_deque *stack);
size_t	comp_idx2(size_t big, size_t n_big, t_deque *stack);
size_t	next_big(t_deque *stack);
size_t	find_big(t_deque *stack);
size_t	set_chunk(size_t capacity);
void	push_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst, size_t big_idx);
void	dq_push_front(t_deque *stack, size_t num);
void	dq_push_rear(t_deque *stack, size_t num);
void	new_node(t_split *head, int num);
void	put_lst(t_split *head, char **splited);
void	fill_stack_a(t_deque *stack_a, t_split *head);
void	handle_error(int err);
void	do_push_swap(t_deque *stack_a);
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
void	sort_copy(int *cp_stack, size_t size);
void	make_sort_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
void	make_hourglass_utl(t_deque *s_a, t_deque *s_b, \
	t_oper *op_lst, size_t i);
void	make_hourglass(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
void	hourglass_sort(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
void	check_rra(t_deque *s_a, t_oper *op_lst, size_t ichunk);
int		check_sort(t_deque *stack);
void	small_sort(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
void	sort_two(t_deque *s_a, t_oper *op_lst);
void	sort_three(t_deque *s_a, t_oper *op_lst, size_t num);
void	sort_four(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
void	sort_five(t_deque *s_a, t_deque *s_b, t_oper *op_lst);
int		ft_atoi_ps(const char *str);
int		check_overlap(t_split *head, int num);

void	write_oper(t_oper *op_lst);
#endif