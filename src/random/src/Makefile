include $(MAKEFILE_SCAFFOLD)

RANDOM_CC_DEPS      := $(call SOURCE_HEADER_PATHS,pcg_basic)

RANDOM_DEP_OBJS     := $(call OBJECT_PATH,pcg_basic)

RANDOM_DEP_PIC_OBJS := $(call PIC_OBJECT_PATH,pcg_basic)

MEMORY_SWAP_STATIC  := $(call EXPORT_STATIC_LIBRARY_PATH, memory_swap)

define RULES
$(call OBJECT,pcg_basic)

$(call PIC_OBJECT,pcg_basic)

$(call TEST_BINARY,pcg_basic)

$(call USER_LIBRARIES,random,\
		      $(RANDOM_CC_DEPS),\
		      $(EMPTY),\
		      $(RANDOM_DEP_PIC_OBJS),\
		      $(RANDOM_DEP_OBJS),\
		      -lmemory_swap_shared,\
		      $(MEMORY_SWAP_STATIC))

$(call TEST_BINARY,random,\
		   $(RANDOM_CC_DEPS),\
		   $(EMPTY),\
		   $(RANDOM_DEP_OBJS),\
		   $(MEMORY_SWAP_STATIC))
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
