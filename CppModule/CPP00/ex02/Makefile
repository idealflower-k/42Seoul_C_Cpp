# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 15:35:14 by sanghwal          #+#    #+#              #
#    Updated: 2023/04/28 15:56:06 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP
# -pedantic-errors
NAME = account

SRCS = Account.cpp \
	tests.cpp

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

.PHONY: all clean fclean re%