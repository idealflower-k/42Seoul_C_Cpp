include ./config/Rules.mk
include ./config/color_rules.mk

NAME = $(PROJECT_NAME)

all bonus clean fclean re:
	# $(MAKE) TOPDIR=`pwd` -C lib $@
	$(MAKE) TOPDIR=`pwd` -C src $@

$(NAME):
	# $(MAKE) TOPDIR=`pwd` -C lib
	$(MAKE) TOPDIR=`pwd` -C src $@

norm:
	@norminette ./src/

leaks: all
	leaks ./$(NAME)

.PHONY: all clean fclean re bonus norm leaks