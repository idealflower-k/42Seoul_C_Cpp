ifndef TOPDIR
		TOPDIR = $(abspath ../../../)
endif

include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/com/Funcs.mk
include $(TOPDIR)/make_config/src/Rules.mk
include $(TOPDIR)/make_config/com/Flags.mk

SRCS :=	light_utils_bonus.c \
		phong_lighting_bonus.c

NAME := light_bonus.a

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/src/BonusSubLibsRecipes.mk
