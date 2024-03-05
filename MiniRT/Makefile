include ./make_config/com/ColorRules.mk
include ./make_config/src/Rules.mk

all bonus clean fclean re:
	$(MAKE) TOPDIR=`pwd` -C ext $@
	$(MAKE) TOPDIR=`pwd` -C lib $@
	$(MAKE) TOPDIR=`pwd` -C src $@

norm:
	norminette src/ lib/

.PHONY: all clean fclean re bonus norm
