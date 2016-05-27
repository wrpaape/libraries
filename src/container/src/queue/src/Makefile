include $(MAKEFILE_SCAFFOLD)


define QUEUE_MODULE
$(call LIBRARIES,$1,\
		 $(EMPTY),\
		 $(EMPTY),\
		 $(EMPTY),\
		 $(EMPTY),\
		 $2,$3)

$(call EXPORT_LIBRARIES,$1)

$(call TEST_BINARY,$1,\
		 $(EMPTY),\
		 $(EMPTY),\
		 $(EMPTY),\
		 $2)
endef

define RULES
$(call QUEUE_MODULE,queue,\
		    -lmemory_utils_shared,\
		    -lmemory_utils_static)

$(call QUEUE_MODULE,bheap,\
		    -lmemory_get_shared -lmemory_set_shared -lmemory_swap_shared,\
		    -lmemory_get_static -lmemory_set_static -lmemory_swap_static)

$(call EXPORT_ALL_HEADERS,container/queue)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
