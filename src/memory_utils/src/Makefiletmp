include $(MAKEFILE_SCAFFOLD)

MEMORY_UTILS_CC_PREQS := $(call SOURCE_HEADER_PATHS,memory_utils)
MEMORY_UTILS_PIC_OBJ  := $(call PIC_OBJECT_PATH,memory_utils)
MEMORY_UTILS_OBJ      := $(call OBJECT_PATH,memory_utils)

define MEMORY_MODULE
$(call LIBRARIES,$1,\
		 $(MEMORY_UTILS_CC_PREQS) $2,\
		 $(EMPTY),\
		 $(MEMORY_UTILS_PIC_OBJ) $3,\
		 $(MEMORY_UTILS_OBJ) $4)

$(call EXPORT_LIBRARIES,$1)

$(call TEST_BINARY,$1,\
		   $(MEMORY_UTILS_CC_PREQS) $2,\
		   $(EMPTY),\
		   $(MEMORY_UTILS_OBJ) $4)
endef

define CHILD_MEMORY_MODULE
$(call MEMORY_MODULE,$1,\
		     $(foreach preq,$2,\
		     		    $(call SOURCE_HEADER_PATHS,$(preq))),\
		     $(foreach preq,$2,\
		     		    $(call PIC_OBJECT_PATH,$(preq))),\
		     $(foreach preq,$2,\
		     		    $(call OBJECT_PATH,$(preq))))
endef

define RULES
$(call OBJECT,memory_utils)

$(call PIC_OBJECT,memory_utils)

$(call TEST_BINARY,memory_utils)

$(foreach accessor,memory_swap memory_get memory_set,\
		   $(call MEMORY_MODULE,$(accessor)))

$(call CHILD_MEMORY_MODULE,memory_put,\
			   memory_set memory_get)

$(call CHILD_MEMORY_MODULE,memory_set_array,\
			   memory_put memory_set memory_get)

$(call CHILD_MEMORY_MODULE,memory_put_array,\
			   memory_put memory_set memory_get)

$(call EXPORT_ALL_HEADERS,memory_utils)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
