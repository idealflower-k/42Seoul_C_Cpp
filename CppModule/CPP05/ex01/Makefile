CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = Bureaucrat

SRCS = main.cpp \
	Bureaucrat.cpp \
	Form.cpp

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
