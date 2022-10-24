/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:04:30 by sanghwal          #+#    #+#             */
/*   Updated: 2022/10/24 15:04:52 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_split
{
	int				num;
	struct s_split	*next;
}	t_split;

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

t_split	*split_num(char *av);
t_split	*new_node(t_split *head, int num);
t_split	*lst_creat(void);
void	put_lst(t_split *head, char **splited);
void	free_lst(t_split *head);
void	handle_error(int err);
int		ft_atoi_ps(const char *str);
int		check_dup(t_split *head, int num);
int		ft_atoi_ps(const char *str);

#endif