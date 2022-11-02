NAME = libft.a

SRCS_1 = ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strncmp.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	get_next_line.c \
	get_next_line_utils.c

	

SRCS_2 = ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

SRCS_BN = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

SRCS = $(SRCS_1) $(SRCS_2)

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BN:.c=.o)

PRINTF = ft_printf/libftprintf.a

PRINTF_DIR = ft_printf

ifdef FLAG_BONUS
OBJS += $(OBJS_BONUS)
endif

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar

ARFLAGS = -rcs

HEADER = libft.h

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR) all

$(NAME): $(OBJS) $(PRINTF)
	cp $(PRINTF) ./$(NAME)
	$(AR) $(ARFLAGS) $@ $^

bonus :
	sleep 1
	make FLAG_BONUS=1 all

clean:
	make -C $(PRINTF_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re: 
	make fclean 
	make all

.PHONY: all clean fclean re bonus
