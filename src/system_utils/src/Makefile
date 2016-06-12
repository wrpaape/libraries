include $(MAKEFILE_SCAFFOLD)

define MODULE
$(call LIBRARIES,$1)
$(call EXPORT_LIBRARIES,$1)
$(call TEST_BINARY,$1)
endef

define RULES
$(call MODULE,system_utils)

$(call MODULE,file_utils)

$(call MODULE,stdio_utils)

$(call EXPORT_ALL_HEADERS,system_utils)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
