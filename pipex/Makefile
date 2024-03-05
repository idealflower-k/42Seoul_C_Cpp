.DEFAULT_GOAL = all
NAME = pipex
# all : ${NAME}

CFLAGS = -Wall -Wextra -Werror -MMD -MP
CPPFLAGS = 
LDFLAGS= -L./libft
LDLIBS = -lft -lftprintf

LIBFT = libft/libft.a
$(LIBFT):
	make -C $(@D)
##################################################################
MANDATORY_DIR = mandatory
MANDATORY_SRCS = pipex.c \
		pipex_utils.c \
		pipex_parsing.c \
		pipex_heredoc.c
		
BONUS_DIR = bonus
BONUS_SRCS = pipex_bonus.c \
	pipex_heredoc_bonus.c \
	pipex_parsing_bonus.c \
	pipex_utils_bonus.c

BONUS_OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.o))
BONUS_DEPS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.d))

OBJS = $(addprefix $(MANDATORY_DIR)/, $(MANDATORY_SRCS:.c=.o))
DEPS = $(addprefix $(MANDATORY_DIR)/, $(MANDATORY_SRCS:.c=.d))

ifdef FLAG_BONUS
OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.o))
DEPS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.d))
endif

-include $(DEPS)

$(OBJS): $(LIBFT)
$(NAME): $(OBJS)
	cc $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

all:
	make -C $(dir $(LIBFT))
	make $(NAME)

bonus:
	make -C $(dir $(LIBFT))
	make FLAG_BONUS=1 $(NAME)

clean:
	make -C $(dir $(LIBFT)) clean
	$(RM) $(OBJS) $(DEPS) $(BONUS_OBJS) $(BONUS_DEPS)

fclean: clean
	make -C $(dir $(LIBFT)) fclean
	$(RM) $(LIBFT) $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re bonus
