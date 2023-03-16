# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 16:48:18 by sanghwal          #+#    #+#              #
#    Updated: 2023/03/16 16:53:11 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all
NAME = fdf

CFLAGS = -Wall -Wextra -Werror -MMD -MP
CPPFLAGS =
LDFLAGS= -L./libft
LDLIBS = -lft -lftprintf

LIBFT = libft/libft.a
$(LIBFT):
	make -C $(@D)

################################################################################
MANDATORY_DIR = philo
MANDATORY_SRCS = main.c

BONUS_DIR = bonus
BONUS_SRCS = 
BONUS_OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.o))
BONUS_DEPS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.d))

OBJS = $(addprefix $(MANDATORY_DIR)/, $(MANDATORY_SRCS:.c=.o))
DEPS = $(addprefix $(MANDATORY_DIR)/, $(MANDATORY_SRCS:.c=.d))

ifdef FLAG_BONUS
OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.o))
DEPS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.d))
endif

-include $(DEPS)

$(OBJS): $(LIBFT) $(MLX)
$(NAME): $(OBJS)
	cc $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

all:
	make -C $(dir $(LIBFT))
	make $(NAME)

bonus:
	make -C $(dir $(LIBFT))
	make FLAG_BONUS=1 $(NAME)

clean:
	make -C $(dir $(LIBFT)) clean
	$(RM) $(OBJS) $(DEPS) $(BONUS_OBJS) $(BONUS_DEPS)

fclean: clean
	make -C $(dir $(LIBFT)) fclean
	$(RM) $(LIBFT) $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re bonus