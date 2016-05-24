include $(MAKEFILE_SCAFFOLD)

MEM_UTILS_CC_DEPS      := $(call SOURCE_HEADER_PATHS,mem_swap)
MEM_UTILS_DEP_PIC_OBJS := $(call PIC_OBJECT_PATH,mem_swap)
MEM_UTILS_DEP_OBJS     := $(call OBJECT_PATH,mem_swap)

define RULES
$(call OBJECT,mem_swap)

$(call PIC_OBJECT,mem_swap)

$(call TEST_BINARY,mem_swap)


$(call USER_LIBRARIES,mem_utils,\
		      $(MEM_UTILS_CC_DEPS),\
		      $(EMPTY),\
		      $(MEM_UTILS_DEP_PIC_OBJS),\
		      $(MEM_UTILS_DEP_OBJS))


$(call TEST_BINARY,mem_utils,\
		   $(MEM_UTILS_CC_DEPS),\
		   $(EMPTY),\
		   $(MEM_UTILS_DEP_OBJS))
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
