include $(AD_CODE_ROOT)/Makefile.common 



DIR = .

INCLUDE = $(COMMONINCLUDE) -I.


LIB = $(COMMONLIBS) $(COMMONLINKLIBS) -lgraphcommon -lgraphbase -lcrypto

CFLAGS += -O2

TARGET = run_graph

SRC := $(foreach dir, $(DIR), $(wildcard $(dir)/*.cpp $(dir)/*.cc))
OBJ := $(patsubst %.cpp,%.o, $(patsubst %.cc,%.o, $(SRC)))

DEPEND := $(shell ls -a ".depend" 2>/dev/null)

all: $(TARGET)
ifeq ($(DEPEND), .depend)
include .depend
endif

include $(AD_CODE_ROOT)/Makefile.tail

