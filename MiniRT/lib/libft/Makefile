ifndef TOPDIR
		TOPDIR = $(abspath ../)
endif
include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/com/Funcs.mk
include $(TOPDIR)/make_config/com/Flags.mk
include $(TOPDIR)/make_config/lib/Rules.mk

NAME := libft.a

HEAD :=	ft_arr.h \
		ft_ascii.h \
		ft_io.h \
		ft_is.h \
		ft_lst.h \
		ft_math.h \
		ft_mem.h \
		ft_str.h \
		libft.h \
		libft_include.h \
		get_next_line_bonus.h

DIRS :=	ft_arr \
		ft_ascii \
		ft_io \
		ft_is \
		ft_lst \
		ft_math \
		ft_mem \
		ft_str

LIBS := $(addsuffix .a, $(addprefix libs/, $(DIRS)))
-include $(DEPS)

include $(TOPDIR)/make_config/lib/Recipes.mk
