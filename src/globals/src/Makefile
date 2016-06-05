include $(MAKEFILE_SCAFFOLD)


define GLOBALS_MODULE
$(call LIBRARIES,$1)

$(call EXPORT_LIBRARIES,$1)

$(call TEST_BINARY,$1)
endef

define RULES
$(call GLOBALS_MODULE,globals)
$(call GLOBALS_MODULE,global_page_size)

$(call EXPORT_ALL_HEADERS,globals)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
