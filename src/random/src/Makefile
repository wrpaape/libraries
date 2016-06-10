include $(MAKEFILE_SCAFFOLD)

RANDOM_CC_PREQS      := $(call HEADER_PATH,random_types)\
			$(foreach module,pcg_basic random_imp,\
					 $(call SOURCE_HEADER_PATHS,$(module)))

RANDOM_PREQ_OBJS     := $(call OBJECT_PATH,pcg_basic)
RANDOM_PREQ_PIC_OBJS := $(call PIC_OBJECT_PATH,pcg_basic)

RANDOM_LD_FLAGS	     := -lutils_shared -lmemory_swap_shared
RANDOM_LIBTOOL_FLAGS := -lutils_static -lmemory_swap_static


define MODULE
$(call LIBRARIES,$1,$2,$(EMPTY),$3,$4,$5,$6)
$(call EXPORT_LIBRARIES,$1)
$(call TEST_BINARY,$1,$2,$(EMPTY),$4,$5)
endef

RANDOM_MODULE = $(call MODULE,$1,\
			      $(RANDOM_CC_PREQS),\
			      $(RANDOM_PREQ_PIC_OBJS),\
			      $(RANDOM_PREQ_OBJS),\
			      $(RANDOM_LD_FLAGS),\
			      $(RANDOM_LIBTOOL_FLAGS))

define RULES
$(call MODULE,pcg_basic)

$(call RANDOM_MODULE,random_nogc)

$(call RANDOM_MODULE,random)

$(call EXPORT_ALL_HEADERS,random)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
