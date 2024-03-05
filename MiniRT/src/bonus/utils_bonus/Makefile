ifndef TOPDIR
		TOPDIR = $(abspath ../../../)
endif

include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/com/Funcs.mk
include $(TOPDIR)/make_config/src/Rules.mk
include $(TOPDIR)/make_config/com/Flags.mk

SRCS :=	destroy_bonus.c \
		color_bonus.c \
		color_oper_bonus.c \
		atod_bonus.c \
		objs_bonus.c \
		error_bonus.c \
		number_bonus.c \
		pixel_bonus.c

NAME := utils_bonus.a

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/src/BonusSubLibsRecipes.mk
