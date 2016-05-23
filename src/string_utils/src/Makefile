include $(MAKEFILE_SCAFFOLD)

LD_FLAGS += -lutils_static

# UNITY_HEADERS_DIR := $(call EXPORT_HEADER_DIRECTORY,unity)
# SUPPORT_HDRS	  := $(foreach spec,internals config,\
# 				$(call HEADER_PATH,unity_$(spec)))
# $(foreach header,$(SUPPORT_HDRS),\
# 		$(call COPY_FILE_TO_DIRECTORY,$(header),$(UNITY_HEADERS_DIR)))


define RULES
$(call USER_LIBRARIES,string_utils)
$(call TEST_BINARY,string_utils)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
