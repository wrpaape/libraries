include $(MAKEFILE_SCAFFOLD)

define RULES
$(call USER_LIBRARIES,time_utils)
$(call TEST_BINARY,time_utils)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
