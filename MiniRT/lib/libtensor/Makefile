ifndef TOPDIR
		TOPDIR = $(abspath ../../)
endif
include $(TOPDIR)/make_config/com/ColorRules.mk
include $(TOPDIR)/make_config/com/Funcs.mk
include $(TOPDIR)/make_config/com/Flags.mk
include $(TOPDIR)/make_config/lib/Rules.mk

NAME := libtensor.a

HEAD := tensor.h

DIRS := libvector \
		libangle \
		libequation \
		libmatrix

LIBS := $(addsuffix .a, $(addprefix libs/, $(DIRS)))
-include $(DEPS)

include $(TOPDIR)/make_config/lib/Recipes.mk
