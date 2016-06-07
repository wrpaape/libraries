include $(MAKEFILE_SCAFFOLD)

SUPPORT_MODULES := ascii utf8

MODULE_MAP = $(foreach module,$(SUPPORT_MODULES),$(call $1,$(module)))


STRING_UTILS_CC_PREQS 	   := $(call MODULE_MAP,SOURCE_HEADER_PATHS)$(SPACE)\
			      $(call HEADER_PATH,token)

STRING_UTILS_LD_PREQS 	   := $(call MODULE_MAP,PIC_OBJECT_PATH)
STRING_UTILS_LD_FLAGS 	   := -lmemory_utils_shared

STRING_UTILS_LIBTOOL_PREQS := $(call MODULE_MAP,OBJECT_PATH)
STRING_UTILS_LIBTOOL_FLAGS := -lmemory_utils_static

define SUPPORT_MODULE_RULES
$(call LIBRARIES,$1)
$(call EXPORT_LIBRARIES,$1)
$(call TEST_BINARY,$1)
endef

define RULES
$(call MODULE_MAP,SUPPORT_MODULE_RULES)

$(call USER_LIBRARIES,string_utils,\
		      $(STRING_UTILS_CC_PREQS),\
		      $(EMPTY),\
		      $(STRING_UTILS_LD_PREQS),\
		      $(STRING_UTILS_LD_FLAGS),\
		      $(STRING_UTILS_LIBTOOL_PREQS),\
		      $(STRING_UTILS_LIBTOOL_FLAGS))

$(call TEST_BINARY,string_utils,\
		   $(STRING_UTILS_CC_PREQS),\
		   $(EMPTY),\
		   $(STRING_UTILS_LD_PREQS),\
		   $(STRING_UTILS_LD_FLAGS))
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
