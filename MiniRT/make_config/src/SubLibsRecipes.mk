all bonus : 
	$(Q)$(call color_printf,$(CYAN),$(NAME),🎯 starting compile $(NAME))
	$(Q)$(MAKE) $(NAME)
	$(Q)$(call color_printf,$(GREEN),$(NAME),🔰 done!)

$(NAME): $(OBJS)
	$(Q)$(call color_printf,$(GREEN),$(NAME),📚 archive object)
	$(AR) $(ARFLAGS) $@ $^
	$(Q)$(MAKE) files="$(NAME)" src_dir=`pwd` dst_dir=$(TOPDIR)/$(MANDATORY_LIB_DIR) link_files
	
clean:
	$(Q)$(MAKE) files="$(NAME)" src_dir=`pwd` dst_dir=$(TOPDIR)/$(MANDATORY_LIB_DIR) unlink_files
	$(Q)$(call color_printf,$(RED),$(NAME),🗑️  remove Objects && Dependency file)
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(Q)$(call color_printf,$(RED),$(NAME),🗑️  remove $(NAME))
	$(RM) $(NAME)
	
re : fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus