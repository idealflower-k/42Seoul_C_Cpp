# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 16:48:18 by sanghwal          #+#    #+#              #
#    Updated: 2023/03/24 17:26:34 by sanghwal         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

include ./config/Rules.mk
include ./config/color_rules.mk

NAME = $(PROJECT_NAME)

all bonus clean fclean re:
	$(MAKE) TOPDIR=`pwd` -C lib $@
	$(MAKE) TOPDIR=`pwd` -C src $@

$(NAME):
	$(MAKE) TOPDIR=`pwd` -C lib
	$(MAKE) TOPDIR=`pwd` -C src $@

norm:
	@norminette ./src/ ./lib/

leaks: all
	leaks ./$(NAME)

.PHONY: all clean fclean re bonus norm leaks