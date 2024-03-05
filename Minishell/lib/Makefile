ifndef TOPDIR
		TOPDIR = $(abspath ..)
endif

include $(TOPDIR)/config/Rules.mk
include $(TOPDIR)/config/color_rules.mk

LIBS = libft

all bonus clean fclean re:
		$(Q)$(foreach lib, $(LIBS), $(MAKE) TOPDIR=$(TOPDIR) -C $(lib) $@;)

.PHONY: all clean fclean re bonus
