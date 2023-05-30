CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes
NAME = miniRT
SRCS = main.c \
	hit_sphere.c \
	object_create.c \
	print.c \
	ray.c \
	scene.c \
	vec3_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re