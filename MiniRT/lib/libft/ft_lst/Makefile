ifndef TOPDIR
		TOPDIR = $(abspath ../../../)
endif

include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/com/Funcs.mk
include $(TOPDIR)/make_config/com/Flags.mk
include $(TOPDIR)/make_config/lib/Rules.mk

SRCS =	ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c

NAME =	libft_lst.a

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/lib/SubLibsRecipes.mk