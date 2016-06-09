include $(MAKEFILE_SCAFFOLD)

GLOB_CTORS_MODULES := glob_ctors glob_page_size_ctor glob_rng_ctor

define GLOB_CTORS_MODULE
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
$(call GLOB_CTORS_MODULE,glob_page_size_ctor)

$(call GLOB_CTORS_MODULE,glob_rng_ctor,\
			-lpcg_basic_shared,\
			-lpcg_basic_static)

$(call GLOB_CTORS_MODULE,glob_ctors)

$(call EXPORT_ALL_HEADERS,glob_ctors)
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)
