include $(MAKEFILE_SCAFFOLD)

define RULES
$(call USER_LIBRARIES,ooga)
$(call USER_BINARY_NO_OBJECT,ooga)
$(call TEST_BINARY,ooga)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)