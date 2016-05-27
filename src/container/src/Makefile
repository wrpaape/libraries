include $(MAKEFILE_SCAFFOLD)

CHILDREN := queue

define MAKE_CHILDREN 
$(call TRIM,make_$1_children:)$(foreach child,$(CHILDREN),
	$(MAKE) $(M_FLAGS) -C $(child) $2)
endef

define RULES
$(call EXPORT_SIBLING_HEADERS,container)

$(call MAKE_CHILDREN,all)

$(call MAKE_CHILDREN,clean)
endef

$(eval $(RULES))

# ensure headers have been exported before making children
all: $(TARGETS) | make_all_children

clean: make_clean_children
	$(RM) $(RM_FLAGS) $(TARGETS)
