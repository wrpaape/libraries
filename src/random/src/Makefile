include $(MAKEFILE_SCAFFOLD)

RANDOM_CC_DEPS      := $(call SOURCE_HEADER_PATHS,pcg_basic)

RANDOM_DEP_OBJS     := $(call OBJECT_PATH,pcg_basic)

RANDOM_DEP_PIC_OBJS := $(call PIC_OBJECT_PATH,pcg_basic)

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
		      -lmemory_swap_static)

$(call TEST_BINARY,random,\
		   $(RANDOM_CC_DEPS),\
		   $(EMPTY),\
		   $(RANDOM_DEP_OBJS),\
		   -lmemory_swap_static)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
