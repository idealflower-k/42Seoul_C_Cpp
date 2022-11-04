# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 19:53:36 by sanghwal          #+#    #+#              #
#    Updated: 2022/11/04 17:20:47 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

CFLAGS = -Wall -Wextra -Werror -MMD -MP
CPPFLAGS = 
LDFLAGS= -L./libft
LDLIBS = -lft -lftprintf

LIBFT = libft/libft.a
$(LIBFT):
	make -C $(@D)
##################################################################
PUSHSWAP = push_swap

PUSHSWAP_SRCS = ps_atoi.c \
			ps_b_to_a.c \
			ps_b_to_a2.c \
			ps_check_sort.c \
			ps_deque_utils.c \
			ps_deque.c \
			ps_error.c \
			ps_make_hourglass.c \
			ps_operator1.c \
			ps_operator3.c \
			ps_operator2.c \
			ps_small_sort.c \
			ps_sort_utils.c \
			ps_sort.c \
			ps_split_lst.c \
			push_swap.c
			
PUSHSWAP_OBJS = $(PUSHSWAP_SRCS:.c=.o)
PUSHSWAP_DEPS = $(PUSHSWAP_SRCS:.c=.d)
-include $(PUSHSWAP_DEPS)

$(PUSHSWAP_OBJS): $(LIBFT)
$(PUSHSWAP): $(PUSHSWAP_OBJS)
##################################################################
CHECKER = checker

CHECKER_SRCS = checker_bonus.c \
			ps_atoi.c \
			ps_b_to_a.c \
			ps_b_to_a2.c \
			ps_check_sort.c \
			ps_deque_utils.c \
			ps_deque.c \
			ps_error.c \
			ps_make_hourglass.c \
			ps_operator1.c \
			ps_operator3.c \
			ps_operator2.c \
			ps_small_sort.c \
			ps_sort_utils.c \
			ps_sort.c \
			ps_split_lst.c \
			push_swap.c

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
CHECKER_DEPS = $(CHECKER_SRCS:.c=.d)
-include $(CHECKER_DEPS)

$(CHECKER): $(CHECKER_OBJS)
$(CHECKER_OBJS): $(LIBFT)
##################################################################
all:
	make -C $(dir $(LIBFT))
	make $(PUSHSWAP)

bonus:
	make -C $(dir $(LIBFT))
	make $(CHECKER)

clean:
	make -C $(dir $(LIBFT)) clean
	$(RM) $(wildcard *.o) $(wildcard *d)

fclean: clean
	make -C $(dir $(LIBFT)) fclean
	$(RM) $(LIBFT) $(PUSHSWAP) $(CHECKER)

re: fclean
	make all

.PHONY: all clean fclean re bonus
