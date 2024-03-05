ifndef TOPDIR
		TOPDIR = $(abspath ../../)
endif

include $(TOPDIR)/config/Rules.mk
include $(TOPDIR)/config/color_rules.mk

bonus :
	$(MAKE) TOPDIR=$(TOPDIR) -C src_b $@

all $(PROJECT_NAME):
	$(MAKE) TOPDIR=$(TOPDIR) -C src_m $@

clean fclean :
	$(MAKE) TOPDIR=$(TOPDIR) -C src_m $@
# $(MAKE) TOPDIR=$(TOPDIR) -C src_b $@

re : fclean
	$(MAKE) TOPDIR=$(TOPDIR) -C src_m $@

.PHONY: all clean fclean re bonus
