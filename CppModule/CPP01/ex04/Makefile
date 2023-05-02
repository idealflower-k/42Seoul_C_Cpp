# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 16:13:06 by sanghwal          #+#    #+#              #
#    Updated: 2023/05/02 16:13:24 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP
# -pedantic-errors
NAME = replace

SRCS = main.cpp \
	replaceFile.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)


all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CFLAGS) $^ -I. -o $@

clean:
		rm -f $(OBJS) $(DEPS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re