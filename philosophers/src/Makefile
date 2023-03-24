# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 17:53:00 by sanghwal          #+#    #+#              #
#    Updated: 2023/03/24 17:53:01 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

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
