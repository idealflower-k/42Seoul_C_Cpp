# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 18:36:26 by sanghwal          #+#    #+#              #
#    Updated: 2023/05/18 16:40:37 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP
# -pedantic-errors

NAME = Fixed

SRCS = main.cpp \
	Fixed.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)


all: $(NAME)

$(NAME): $(OBJS)
				$(CXX) $(CXXFLAGS) $^ -I. -o $@

clean:
				rm -f $(OBJS) $(DEPS)

fclean: clean
				rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
