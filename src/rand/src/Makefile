include $(MAKEFILE_SCAFFOLD)

RAND_CC_PREQS	  := $(call SOURCE_HEADER_PATHS,pcg_basic)
RAND_LD_PIC_PREQS := $(call PIC_OBJECT_PATH,pcg_basic)
RAND_LD_PREQS	  := $(call OBJECT_PATH,pcg_basic)


define RULES
$(call OBJECT,pcg_basic)
$(call PIC_OBJECT,pcg_basic)
$(call TEST_BINARY,pcg_basic)
$(call USER_LIBRARIES,rand,$(RAND_CC_PREQS),$(EMPTY),$(RAND_LD_PIC_PREQS),$(RAND_LD_PREQS))
$(call TEST_BINARY,rand,$(RAND_CC_PREQS),$(EMPTY),$(RAND_LD_PREQS))
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
