all bonus:
	$(Q)$(foreach dir, $(DIRS), $(MAKE) TOPDIR=$(TOPDIR) -C $(dir) $(J) $@;)
	$(Q)$(MAKE) files="$(HEAD)" src_dir=`pwd`/includes dst_dir=$(TOPDIR)/includes link_files
	$(Q)$(call color_printf,$(GREEN),$(NAME),🔰 done!)
	
fclean clean:
	$(Q)$(MAKE) files="$(HEAD)" src_dir=`pwd` dst_dir=$(TOPDIR)/includes unlink_files
	$(Q)$(foreach dir, $(DIRS), $(MAKE) TOPDIR=$(TOPDIR) -C $(dir) $(J) $@;)

re: fclean
	$(Q)$(foreach dir, $(DIRS), $(MAKE) TOPDIR=$(TOPDIR) -C $(dir) $(J) $@;)
	$(MAKE) all

norm : 
	norminette .

.PHONY: all clean fclean re bonus norm
