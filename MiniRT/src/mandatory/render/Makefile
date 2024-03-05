ifndef TOPDIR
		TOPDIR = $(abspath ../../../)
endif

include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/com/Funcs.mk
include $(TOPDIR)/make_config/src/Rules.mk
include $(TOPDIR)/make_config/com/Flags.mk

SRCS :=	ray.c \
		render.c \
		find_obj.c \
		render_plane.c \
		render_sphere.c \
		render_cylinder.c \
		render_cylinder2.c

NAME := render.a

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/src/SubLibsRecipes.mk
