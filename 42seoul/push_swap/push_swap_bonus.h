/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:46:30 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/04 19:17:49 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"
#include <stdio.h>
void	do_op(t_deque *s_a, t_deque *s_b, char *cmd);
void	checker(t_deque *s_a, t_deque *s_b);
void	set_checker(t_deque *stack_a);
t_split	*split_num(char *av, t_split *head);
#endif