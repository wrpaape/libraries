include $(MAKEFILE_SCAFFOLD)

SUP_HDRS := $(foreach spec,config internals,$(call HEADER_PATH,unity_$(spec)))

define RULES
$(call USER_LIBRARIES,unity,$(SUP_HDRS),-DUNITY_INCLUDE_CONFIG_H)
$(call TEST_BINARY,unity,$(SUP_HDRS),-DUNITY_INCLUDE_CONFIG_H)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
