include $(MAKEFILE_SCAFFOLD)

define RULES
$(call USER_LIBRARIES,utils)
$(call TEST_BINARY,utils)
endef

$(eval $(RULES))
# $(info $(TARGETS))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
