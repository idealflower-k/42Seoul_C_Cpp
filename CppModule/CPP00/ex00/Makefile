CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP
# -pedantic-errors

NAME = megaphone

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re