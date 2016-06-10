include $(MAKEFILE_SCAFFOLD)

define RULES
$(call USER_LIBRARIES,bit_vector)
$(call TEST_BINARY,bit_vector,
		   $(EMPTY),
		   $(EMPTY),
		   $(EMPTY),
		   -lrandom_shared)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
