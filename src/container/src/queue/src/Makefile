include $(MAKEFILE_SCAFFOLD)

PROJECT_ROOT := ../..


MEMORY_UTILS_CC_DEPS := $(call SOURCE_HEADER_PATHS,memory_utils)
MEMORY_UTILS_PIC_OBJ := $(call PIC_OBJECT_PATH,memory_utils)
MEMORY_UTILS_OBJ     := $(call OBJECT_PATH,memory_utils)

define QUEUE_MODULE
$(call LIBRARIES,$(module),\
		 $(MEMORY_UTILS_CC_DEPS),\
		 $(EMPTY),\
		 $(MEMORY_UTILS_PIC_OBJ),\
		 $(MEMORY_UTILS_OBJ))

$(call EXPORT_LIBRARIES,$(module))

$(call TEST_BINARY,$(module),\
		   $(MEMORY_UTILS_CC_DEPS),\
		   $(EMPTY),\
		   $(MEMORY_UTILS_OBJ))
endef

define RULES
$(call OBJECT,memory_utils)

$(call PIC_OBJECT,memory_utils)

$(call TEST_BINARY,memory_utils)

$(foreach module,queue bheap,\
	$(call QUEUE_MODULE,$(module)))

$(call EXPORT_ALL_HEADERS,memory_utils)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
