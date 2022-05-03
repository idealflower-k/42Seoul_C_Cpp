NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar
AFLAGS = rcs
RM = rm
TARGET = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
INCLUDES = includes

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@ -I $(INCLUDES)

$(NAME) : $(OBJS)
	$(AR) $(AFLAGS) $@ $^

clean :
	$(RM) -f $(OBJS)

fclean : clean
	$(RM) -f $(NAME)

re : fclean all

