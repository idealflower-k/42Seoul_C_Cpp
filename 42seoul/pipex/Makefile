# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 19:53:36 by sanghwal          #+#    #+#              #
#    Updated: 2022/11/23 18:08:05 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3
CPPFLAGS = 
LDFLAGS= -L./libft
LDLIBS = -lft -lftprintf

LIBFT = libft/libft.a
$(LIBFT):
	make -C $(@D)
##################################################################
NAME = pipex

PIPEX_DIR = .
PIPEX_SRCS = pipex.c \
		pipex_utils.c \
		pipex_parsing.c

PIPEX_OBJS = $(addprefix $(PIPEX_DIR)/, $(PIPEX_SRCS:.c=.o))
PIPEX_DEPS = $(addprefix $(PIPEX_DIR)/,$(PIPEX_SRCS:.c=.d))
-include $(PIPEX_DEPS)

$(PIPEX_OBJS): $(LIBFT)
$(NAME): $(PIPEX_OBJS)
	cc $(LDFLAGS) $(PIPEX_OBJS) $(LDLIBS) -o $@
##################################################################
# CHECKER = checker

# CHECKER_DIR = bonus
# CHECKER_SRCS = checker_bonus.c \
# 	ps_atoi_bonus.c \
# 	ps_check_sort_bonus.c \
# 	ps_deque_bonus.c \
# 	ps_deque_utils_bonus.c \
# 	ps_error_bonus.c \
# 	ps_operator1_bonus.c \
# 	ps_operator2_bonus.c \
# 	ps_operator3_bonus.c \
# 	ps_sort_utils_bonus.c \
# 	ps_split_lst_bonus.c \
# 	ps_free_bonus.c

# CHECKER_OBJS = $(addprefix $(CHECKER_DIR)/, $(CHECKER_SRCS:.c=.o))
# CHECKER_DEPS = $(addprefix $(CHECKER_DIR)/, $(CHECKER_SRCS:.c=.d))
# -include $(CHECKER_DEPS)

# $(CHECKER_OBJS): $(LIBFT)
# $(CHECKER): $(CHECKER_OBJS)
# 	cc $(LDFLAGS) $(CHECKER_OBJS) $(LDLIBS) -o $@
##################################################################
all:
	make -C $(dir $(LIBFT))
	make $(NAME)

bonus:
	make -C $(dir $(LIBFT))
	make $(NAME)

clean:
	make -C $(dir $(LIBFT)) clean
	$(RM) $(PIPEX_OBJS) $(PIPEX_DEPS)

fclean: clean
	make -C $(dir $(LIBFT)) fclean
	$(RM) $(LIBFT) $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re bonus
