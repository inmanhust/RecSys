include $(AD_CODE_ROOT)/Makefile.common 

DIR = .  

INCLUDE = $(COMMONINCLUDE) -I.

LIB = $(COMMONLIBS)

TARGETSO = libbasegraph.so

SRC := $(foreach dir, $(DIR), $(wildcard $(dir)/*.cpp))

OBJ := $(patsubst %.cpp,%.o, $(SRC))

DEPEND := $(shell ls -a ".depend" 2>/dev/null)

all: $(TARGETSO)

ifeq ($(DEPEND), .depend)
include .depend
endif

include $(AD_CODE_ROOT)/Makefile.so.tail
 
