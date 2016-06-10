include $(MAKEFILE_SCAFFOLD)

define RULES
$(call USER_LIBRARIES,utils)
$(call TEST_BINARY,utils,\
		   $(EMPTY),\
		   $(EMPTY),\
		   $(EMPTY),\
		   -lm)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
