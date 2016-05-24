include $(MAKEFILE_SCAFFOLD)

define RULES
$(call OBJECT,nlg)
$(call TEST_BINARY,nlg)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
