include $(MAKEFILE_SCAFFOLD)

MEMORY_UTILS_CC_DEPS := $(call SOURCE_HEADER_PATHS,memory_utils)
MEMORY_UTILS_PIC_OBJ := $(call PIC_OBJECT_PATH,memory_utils)
MEMORY_UTILS_OBJ     := $(call OBJECT_PATH,memory_utils)

define RULES
$(call OBJECT,memory_utils)

$(call PIC_OBJECT,memory_utils)

$(call TEST_BINARY,memory_utils)

$(call LIBRARIES,memory_swap,\
		 $(MEMORY_UTILS_CC_DEPS),\
		 $(EMPTY),\
		 $(MEMORY_UTILS_PIC_OBJ),\
		 $(MEMORY_UTILS_OBJ))

$(call EXPORT_LIBRARIES,memory_swap)

$(call TEST_BINARY,memory_swap,\
		   $(MEMORY_UTILS_CC_DEPS),\
		   $(EMPTY),\
		   $(MEMORY_UTILS_OBJ))

$(call EXPORT_ALL_HEADERS,memory_utils)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
