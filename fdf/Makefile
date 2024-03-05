.DEFAULT_GOAL = all
NAME = fdf

CFLAGS = -Wall -Wextra -Werror -MMD -MP
CPPFLAGS =
LDFLAGS= -L./libft -L./minilibx_macos
LDLIBS = -lft -lftprintf -lmlx

LIBFT = libft/libft.a
$(LIBFT):
	make -C $(@D)
	
MLX = minilibx_macos/libmlx.a
$(MLX):
	make -C $(@D)
################################################################################
MANDATORY_DIR = mandatory
MANDATORY_SRCS = fdf.c \
				map_pars.c \
				map_utils.c \
				draw_line.c \
				rotation_coord.c \
				coords_utils.c \
				fdf_hook.c \
				utils.c \
				projection.c \
				color.c \
				color_utils.c \
				img.c \
				move_coord.c \
				draw_utils.c

BONUS_DIR = bonus
BONUS_SRCS = fdf_bonus.c \
				map_pars_bonus.c \
				map_utils_bonus.c \
				draw_line_bonus.c \
				rotation_coord_bonus.c \
				coords_utils_bonus.c \
				fdf_hook_bonus.c \
				utils_bonus.c \
				projection_bonus.c \
				color_bonus.c \
				color_utils_bonus.c \
				img_bonus.c \
				move_coord_bonus.c \
				draw_utils_bonus.c

BONUS_OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.o))
BONUS_DEPS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.d))

OBJS = $(addprefix $(MANDATORY_DIR)/, $(MANDATORY_SRCS:.c=.o))
DEPS = $(addprefix $(MANDATORY_DIR)/, $(MANDATORY_SRCS:.c=.d))

ifdef FLAG_BONUS
OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.o))
DEPS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.d))
endif

-include $(DEPS)

$(OBJS): $(LIBFT) $(MLX)
$(NAME): $(OBJS)
	cc $(LDFLAGS) $(OBJS) $(LDLIBS) -framework OpenGL -framework AppKit -o $@

all:
	make -C $(dir $(LIBFT))
	make -C $(dir $(MLX))
	make $(NAME)

bonus:
	make -C $(dir $(LIBFT))
	make -C $(dir $(MLX))
	make FLAG_BONUS=1 $(NAME)

clean:
	make -C $(dir $(LIBFT)) clean
	make -C $(dir $(MLX)) clean
	$(RM) $(OBJS) $(DEPS) $(BONUS_OBJS) $(BONUS_DEPS)

fclean: clean
	make -C $(dir $(LIBFT)) fclean
	make -C $(dir $(MLX)) clean
	$(RM) $(LIBFT) $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re bonus