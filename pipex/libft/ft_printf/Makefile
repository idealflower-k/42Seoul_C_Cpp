# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 14:51:23 by sanghwal          #+#    #+#              #
#    Updated: 2022/11/23 18:08:16 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3
CPPFLAGS = 
ARFLAGS = -rcs

FTPRINTF = libftprintf.a

FTPRINTF_SRC = ft_char.c \
	ft_hexa.c \
	ft_int.c \
	ft_printf.c \
	ft_str.c \
	ft_unsigned_itoa.c

FTPRINTF_OBJS = $(FTPRINTF_SRC:.c=.o)
FTPRINTF_DEPS = $(FTPRINTF_SRC:.c=.d)
-include $(FTPRINTF_DEPS)

$(FTPRINTF): $(FTPRINTF_OBJS)
	$(AR) $(ARFLAGS) $@ $^
	cp $(FTPRINTF) ../$(FTPRINTF)

all:
	make $(FTPRINTF)

clean:
	$(RM) $(FTPRINTF_OBJS) $(FTPRINTF_DEPS)

fclean: clean
	$(RM) $(FTPRINTF)

re: fclean
	make all

.PHONY: all clean fclean re