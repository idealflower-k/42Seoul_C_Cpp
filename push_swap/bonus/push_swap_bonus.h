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

void	free_split(char **splited);
void	do_op(t_deque *s_a, t_deque *s_b, char *cmd);
void	checker(t_deque *s_a, t_deque *s_b);
void	set_checker(t_deque *stack_a);
t_split	*split_num(char *av, t_split *head);
t_split	*lst_creat(void);
t_deque	*stack_a_creat(t_deque *stack_a, t_split *head);
t_deque	*deque_creat(size_t size);
size_t	dq_pop_front(t_deque *stack);
size_t	dq_pop_rear(t_deque *stack);
int		*copy_stack(t_deque *stack, int *cp_stack);
void	push_a(t_deque *s_a, t_deque *s_b, t_oper *op_lst, size_t big_idx);
void	dq_push_front(t_deque *stack, size_t num);
void	dq_push_rear(t_deque *stack, size_t num);
void	new_node(t_split *head, int num);
void	put_lst(t_split *head, char **splited);
void	fill_stack_a(t_deque *stack_a, t_split *head);
void	handle_error(int err);
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
int		check_sort(t_deque *stack);
int		ft_atoi_ps(const char *str);
int		check_overlap(t_split *head, int num);
void	free_oper_lst(t_oper *op_lst);
void	free_splited(char **splited);
void	free_split_lst(t_split *head);

#endif