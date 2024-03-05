ifndef TOPDIR
		TOPDIR = $(abspath ../../../)
endif

include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/com/Funcs.mk
include $(TOPDIR)/make_config/src/Rules.mk
include $(TOPDIR)/make_config/com/Flags.mk

SRCS :=	ray_bonus.c \
		render_bonus.c \
		apply_option_bonus.c \
		thread_bonus.c \
		find_obj_bonus.c \
		render_plane_bonus.c \
		render_sphere_bonus.c \
		render_cylinder_bonus.c \
		render_cylinder2_bonus.c \
		set_cylinder_uv_bonus.c \
		render_cone_bonus.c \
		render_cone2_bonus.c

NAME := render_bonus.a

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/src/BonusSubLibsRecipes.mk
