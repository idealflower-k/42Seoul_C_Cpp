CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = converter

SRCS = main.cpp \
	ScalarConverter.cpp \
	utils.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -I. -o $@

clean:
	rm -f $(OBJS) $(DEPS) *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
