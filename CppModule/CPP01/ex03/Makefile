# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 16:25:02 by sanghwal          #+#    #+#              #
#    Updated: 2023/05/04 13:45:14 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP
# -pedantic-errors

NAME = weapon

SRCS = main.cpp \
	Weapon.cpp \
	HumanA.cpp \
	HumanB.cpp \

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