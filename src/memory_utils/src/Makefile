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

define MEMORY_ACTION_MODULE
$(call MEMORY_MODULE,$(call TRIM,memory_$1),\
		     $(call HEADER_PATH,$(call TRIM,memory_$1_width)))
endef

define MEMORY_ARRAY_ACTION_MODULE
$(call MEMORY_MODULE,$(call TRIM,memory_$1_array),\
		     $(foreach aa_cc_preq,$(call TRIM,memory_$2_width) word_rem_utils,\
				          $(call HEADER_PATH,$(aa_cc_preq))))
endef


define RULES
$(call OBJECT,memory_utils)

$(call PIC_OBJECT,memory_utils)

$(call TEST_BINARY,memory_utils)

$(foreach action,swap get set put,\
		 $(call MEMORY_ACTION_MODULE,$(action)))


$(foreach array_action,put,\
		 $(call MEMORY_ARRAY_ACTION_MODULE,$(array_action),$(array_action)))

$(call MEMORY_ARRAY_ACTION_MODULE,copy,set)

$(call EXPORT_ALL_HEADERS,memory_utils)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
