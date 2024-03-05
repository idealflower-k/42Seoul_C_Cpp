NAME = libftprintf.a

LIBFT = ./libft/libft.a

LIBFT_DIR = libft

SRCS = ft_char.c \
	ft_hexa.c \
	ft_int.c \
	ft_printf.c \
	ft_str.c \
	ft_unsigned_itoa.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar

ARFLAGS = -rcs

HEADER = ft_printf.h

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) ./$(NAME)
	$(AR) $(ARFLAGS) $@ $^

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re