# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 17:54:29 by sanghwal          #+#    #+#              #
#    Updated: 2023/03/28 19:41:04 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../../)
endif

include $(TOPDIR)/config/Rules.mk
include $(TOPDIR)/config/color_rules.mk

NAME = $(PROJECT_NAME)

DIRS = parser \
	unit_test \
	meta

HEADS = 

SRCS = main.c

LIBS = $(addsuffix .a, $(addprefix lib/, $(DIRS)))

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

all bonus :
	$(Q)$(foreach dir, $(DIRS), $(MAKE) TOPDIR=$(TOPDIR) -C $(dir) $@;)
	$(Q)$(call color_printf,$(YELLOW),$(NAME),🎯 Start compiling)
	$(MAKE) $(NAME)
	$(Q)$(call color_printf,$(GREEN),$(NAME),✨ compiled!)

$(NAME): $(OBJS) $(LIBS)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@
	$(MAKE) files="$(HEADS)" src_dir=`pwd`/includes dst_dir=$(TOPDIR)/includes link_files
	$(MAKE) files="$(NAME)" src_dir=`pwd` dst_dir=$(TOPDIR) link_files
	
clean:
	$(Q)$(foreach dir, $(DIRS), $(MAKE) TOPDIR=$(TOPDIR) -C $(dir) $@;)
	$(MAKE) files="$(HEADS)" src_dir=`pwd` dst_dir=$(TOPDIR)/includes unlink_files
	$(RM) $(DEPS) $(OBJS)

fclean: clean
	$(Q)$(foreach dir, $(DIRS), $(MAKE) TOPDIR=$(TOPDIR) -C $(dir) $@;)
	$(MAKE) files="$(NAME)" src_dir=`pwd` dst_dir=$(TOPDIR) unlink_files
	$(RM) $(NAME)

re: fclean
	$(Q)$(foreach dir, $(DIRS), $(MAKE) TOPDIR=$(TOPDIR) -C $(dir) $@;)
	$(MAKE)


.PHONY: all clean fclean re bonus