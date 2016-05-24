include $(MAKEFILE_SCAFFOLD)

PARALLEL_CC_DEPS      := $(call SOURCE_HEADER_PATHS,handle_semaphore) $(call HEADER_PATH,handle_pthread)
PARALLEL_DEP_PIC_OBJS := $(call PIC_OBJECT_PATH,handle_semaphore)
PARALLEL_DEP_OBJS     := $(call OBJECT_PATH,handle_semaphore)
PARALLEL_LD_LIBS      := -lstring_utils_static -ltime_utils_static -lpthread

define RULES
$(call OBJECT,handle_semaphore)

$(call PIC_OBJECT,handle_semaphore)

$(call TEST_BINARY,handle_semaphore)


$(call USER_LIBRARIES,parallel,\
		      $(PARALLEL_CC_DEPS),\
		      $(EMPTY),\
		      $(PARALLEL_DEP_PIC_OBJS),\
		      $(PARALLEL_DEP_OBJS),\
		      $(PARALLEL_LD_LIBS))


$(call TEST_BINARY,parallel,\
		   $(PARALLEL_CC_DEPS),\
		   $(EMPTY),\
		   $(PARALLEL_DEP_OBJS),\
		   $(PARALLEL_LD_LIBS))
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
