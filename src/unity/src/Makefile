include $(MAKEFILE_SCAFFOLD)

UNITY_HEADERS_DIR := $(call EXPORT_HEADER_DIRECTORY,unity)
SUPPORT_HDRS	  := $(foreach spec,internals config,\
			$(call HEADER_PATH,unity_$(spec)))
define RULES
$(foreach header,$(SUPPORT_HDRS),\
	$(call COPY_FILE_TO_DIRECTORY,$(header),$(UNITY_HEADERS_DIR)))

$(call USER_LIBRARIES,unity,$(SUPPORT_HDRS))
$(call TEST_BINARY,unity,$(SUPPORT_HDRS))
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
