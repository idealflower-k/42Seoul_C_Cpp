# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 15:38:15 by sanghwal          #+#    #+#              #
#    Updated: 2022/12/13 20:52:21 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all
NAME = fdf

CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3
CPPFLAGS =
LDFLAGS= -L./libft -L./minilibx_macos
LDLIBS = -lft -lftprintf -lmlx

LIBFT = libft/libft.a
$(LIBFT):
	make -C $(@D)
	
MLX = minilibx_macos/libmlx.a
$(MLX):
	make -C $(@D)
################################################################################
MANDATORY_DIR = mandatory
MANDATORY_SRCS = fdf_parsing.c

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
	cc $(LDFLAGS) $(OBJS) $(LDLIBS) -framework OpenGL -framework AppKit -o $@
# gcc draw_many_circles.c libmlx.a -framework OpenGL -framework AppKit
all:
	make -C $(dir $(LIBFT))
	make -C $(dir $(MLX))
	make $(NAME)

bonus:
	make -C $(dir $(LIBFT))
	make -C $(dir $(MLX))
	make FLAG_BONUS=1 $(NAME)

clean:
	make -C $(dir $(LIBFT)) clean
	make -C $(dir $(MLX)) clean
	$(RM) $(OBJS) $(DEPS) $(BONUS_OBJS) $(BONUS_DEPS)

fclean: clean
	make -C $(dir $(LIBFT)) fclean
	make -C $(dir $(MLX)) clean
	$(RM) $(LIBFT) $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re bonus