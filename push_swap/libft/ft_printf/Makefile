.DEFAULT_GOAL = all

CFLAGS = -Wall -Wextra -Werror -MMD -MP
CPPFLAGS = 
ARFLAGS = -rcs

FTPRINTF = libftprintf.a

FTPRINTF_SRC = ft_char.c \
	ft_hexa.c \
	ft_int.c \
	ft_printf.c \
	ft_str.c \
	ft_unsigned_itoa.c

FTPRINTF_OBJS = $(FTPRINTF_SRC:.c=.o)
FTPRINTF_DEPS = $(FTPRINTF_SRC:.c=.d)
-include $(FTPRINTF_DEPS)

$(FTPRINTF): $(FTPRINTF_OBJS)
	$(AR) $(ARFLAGS) $@ $^
	cp $(FTPRINTF) ../$(FTPRINTF)

all:
	make $(FTPRINTF)

clean:
	$(RM) $(wildcard *.o) $(wildcard *.d)

fclean: clean
	$(RM) $(FTPRINTF)

re: fclean
	make all

.PHONY: all clean fclean re