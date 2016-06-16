include $(MAKEFILE_SCAFFOLD)


define SET_MODULE
$(call LIBRARIES,$1)

$(call EXPORT_LIBRARIES,$1)

$(call TEST_BINARY,$1,\
		 $(EMPTY),\
		 $(EMPTY),\
		 $(EMPTY),\
		 $2)
endef

define RULES
$(call SET_MODULE,bit_vector,\
		    -lrandom_shared)

$(call EXPORT_ALL_HEADERS,container/set)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
