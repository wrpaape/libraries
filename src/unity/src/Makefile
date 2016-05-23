include $(MAKEFILE_SCAFFOLD)

define RULES
$(call USER_LIBRARIES,unity,$(SUPPORT_HDRS))
$(call TEST_BINARY,unity,$(SUPPORT_HDRS))
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
