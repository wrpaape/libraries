include $(MAKEFILE_SCAFFOLD)

define RULES
$(call OBJECT,memory_utils)

$(call PIC_OBJECT,memory_utils)

$(call TEST_BINARY,memory_utils)

$(foreach module,queue bheap,\
	$(call QUEUE_MODULE,$(module)))

$(call EXPORT_ALL_HEADERS,memory_utils)
endef

SRC_DIR = src
MFLAGS  = -j5 LAST=550

all clean:
	$(MAKE) $(MFLAGS) -C $(SRC_DIR) $@
