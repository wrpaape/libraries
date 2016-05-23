include $(MAKEFILE_SCAFFOLD)


EXT_LIBS_OBJ	 := $(call OBJECT_PATH,ext_libs)
PARALLEL_CC_DEPS := $(call SOURCE_HEADER_PATHS,handle_semaphore) $(call HEADER_PATH,handle_pthread)
PARALLEL_LD_DEPS := $(call PIC_OBJECT_PATH,handle_semaphore)
PARALLEL_AR_DEPS := $(call OBJECT_PATH,handle_semaphore)
PARALLEL_LD_LIBS := -lstring_utils_static -ltime_utils_static -lpthread

# $(call LINK_OBJECTS,$(EXT_LIBS_OBJ),$(EMPTY),$(EXTERNAL_LIBRARIES))
# $(call USER_SHARED_LIBRARY,parallel,\
# 		      $(PARALLEL_CC_DEPS),\
# 		      $(EMPTY),\
# 		      $(PARALLEL_LD_PIC_DEPS),\
# 		      $(EXTERNAL_LIBRARIES))
# $(call EXPORT_STATIC_LIBRARY,parallel)
define RULES
$(call OBJECT,handle_semaphore)

$(call PIC_OBJECT,handle_semaphore)

$(call TEST_BINARY,handle_semaphore)


$(call USER_LIBRARIES,parallel,\
		      $(PARALLEL_CC_DEPS),\
		      $(EMPTY),\
		      $(PARALLEL_LD_DEPS),\
		      $(PARALLEL_AR_DEPS),\
		      $(PARALLEL_LD_LIBS))


$(call TEST_BINARY,parallel,\
		   $(PARALLEL_CC_DEPS),\
		   $(EMPTY),\
		   $(PARALLEL_LD_DEPS),\
		   $(PARALLEL_LD_LIBS))
endef

$(eval $(RULES))

all: $(TARGETS)

clean:
	$(RM) $(RM_FLAGS) $(TARGETS)

# PARALLEL_TRNR_SRC_DEP  = $(PARALLEL_TEST_SRC)
# PARALLEL_OBJ_DEP       = $(PARALLEL_SRC) $(PARALLEL_HDR) $(HANDLE_PTHREAD_HDR) $(HANDLE_SEMAPHORE_HDR)
# PARALLEL_PIC_OBJ_DEP   = $(PARALLEL_OBJ_DEP)
# PARALLEL_TRNR_OBJ_DEP  = $(PARALLEL_TRNR_SRC)
# PARALLEL_TEST_OBJ_DEP  = $(PARALLEL_TEST_SRC) $(PARALLEL_OBJ_DEP)
# PARALLEL_TEST_BIN_DEP  = $(PARALLEL_TEST_OBJ) $(PARALLEL_TRNR_OBJ)
# PARALLEL_SHARED_DEP    = $(PARALLEL_PIC_OBJ) $(HANDLE_SEMAPHORE_PIC_OBJ)
# PARALLEL_STATIC_DEP    = $(PARALLEL_OBJ) $(HANDLE_SEMAPHORE_OBJ)
# PARALLEL_MKDIR_HDR_DEP = $(EMPTY)
# PARALLEL_CP_HDR_DEP    = $(PARALLEL_HDR) $(PARALLEL_MKDIR_HDR)
# PARALLEL_CP_SHARED_DEP = $(PARALLEL_SHARED)
# PARALLEL_CP_STATIC_DEP = $(PARALLEL_STATIC)


# .PHONY: all clean


# # environment config
# # ==============================================================================
# # USER_BIN           = ~/bin                = export binaries dest dir
# # C_LIBRARY_HEADERS  = ~C_LIBRARIES/include = module mkdir (for header) location
# # C_SHARED_LIBRARIES = ~C_LIBRARIES/shared  = export shared libraries dest dir
# # C_STATIC_LIBRARIES = ~C_LIBRARIES/static  = export static libraries dest dir
# # UNITY_SCRIPTS      = ~C_ROOT/unity/auto   = unity scripts folder


# # utility config
# # ==============================================================================
# # utilities
# CC    = gcc
# AR    = ar
# RUBY  = ruby
# MKDIR = mkdir
# CP    = cp
# RM    = rm

# # library dependencies
# DEP_LIBS      = pthread time_utils_static
# TEST_DEP_LIBS = unity_shared

# # flags
# CFLAGS      = -g -I$(HDR_DIR) -std=c99 -Wall -D__USE_FIXED_PROTOTYPES__
# ARFLAGS     = rcs
# PIC_FLAG    = -fpic
# SHARED_FLAG = -shared
# LFLAGS      = $(call MAP_LFLAGS,$(DEP_LIBS))
# TEST_LFLAGS = $(call MAP_LFLAGS,$(TEST_DEP_LIBS))
# RM_FLAGS    = -rf

# # unity test runner generator script
# GENERATE_TEST_RUNNER = $(call PATH_JOIN,$(UNITY_SCRIPTS) generate_test_runner.rb)


# # directory config
# # ==============================================================================
# # source files
# SRC    = src
# # header files
# HDR    = $(SRC)
# # all generated object files
# OBJ    = obj
# # generated module binary files
# BIN    = bin
# # generated shared library files
# SHARED = shared
# # generated static library files
# STATIC = static
# # test source and generated test binary files
# TEST   = test
# # generated test_runner source files
# TRNR   = test_runners

# # paths relative project root, 'ROOT_DIR'
# ROOT_DIR      = ..
# SRC_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(SRC))
# HDR_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(HDR))
# TEST_SRC_DIR  = $(call PATH_JOIN,$(ROOT_DIR) $(TEST))
# TRNR_SRC_DIR  = $(call PATH_JOIN,$(TEST_SRC_DIR) $(TRNR))
# OBJ_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(OBJ))
# PIC_OBJ_DIR   = $(OBJ_DIR)
# TEST_OBJ_DIR  = $(OBJ_DIR)
# TRNR_OBJ_DIR  = $(OBJ_DIR)
# BIN_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(BIN))
# TEST_BIN_DIR  = $(TEST_SRC_DIR)
# SHARED_DIR    = $(call PATH_JOIN,$(ROOT_DIR) $(SHARED))
# STATIC_DIR    = $(call PATH_JOIN,$(ROOT_DIR) $(STATIC))


# # filename config
# # ==============================================================================
# LIB_PFX  = lib
# TEST_SFX = _test
# TRNR_SFX = _test_runner

# # prefixes
# SRC_PFX       = $(EMPTY)
# HDR_PFX       = $(EMPTY)
# TEST_SRC_PFX  = $(EMPTY)
# TRNR_SRC_PFX  = $(EMPTY)
# OBJ_PFX       = $(EMPTY)
# PIC_OBJ_PFX   = pic_
# TRNR_OBJ_PFX  = $(EMPTY)
# TEST_OBJ_PFX  = $(EMPTY)
# BIN_PFX       = $(EMPTY)
# TEST_BIN_PFX  = $(EMPTY)
# SHARED_PFX    = $(LIB_PFX)
# STATIC_PFX    = $(LIB_PFX)
# MKDIR_HDR_PFX = $(EMPTY)

# # suffixes (including extensions)
# SRC_SFX       = .c
# HDR_SFX       = .h
# TEST_SRC_SFX  = $(call CONCAT,$(TEST_SFX) $(SRC_SFX))
# TRNR_SRC_SFX  = $(call CONCAT,$(TRNR_SFX) $(SRC_SFX))
# OBJ_SFX       = .o
# PIC_OBJ_SFX   = $(OBJ_SFX)
# TEST_OBJ_SFX  = $(call CONCAT,$(TEST_SFX) $(OBJ_SFX))
# TRNR_OBJ_SFX  = $(call CONCAT,$(TRNR_SFX) $(OBJ_SFX))
# BIN_SFX       = $(EMPTY)
# TEST_BIN_SFX  = $(TEST_SFX)
# SHARED_SFX    = $(call CONCAT,_ $(SHARED) .so)
# STATIC_SFX    = $(call CONCAT,_ $(STATIC) .a)
# MKDIR_HDR_SFX = $(EMPTY)


# # functions
# # ==============================================================================
# # string operations
# JOIN       = $(subst $(SPACE),$2,$(strip $1))
# CONCAT     = $(call JOIN,$1,$(EMPTY))
# PATH_JOIN  = $(call JOIN,$1,$(PATH_DELIM))
# VAR_JOIN   = $(call JOIN,$1,$(VAR_DELIM))
# MAP_LFLAGS = $(foreach lib,$1,$(call CONCAT,-l $(lib)))

# # variable generation, expansion
# EXPAND_VAR      = $($(call VAR_JOIN,$1))
# EXPAND_DIR      = $(call EXPAND_VAR,$1 DIR)
# EXPAND_PFX      = $(call EXPAND_VAR,$1 PFX)
# EXPAND_SFX      = $(call EXPAND_VAR,$1 SFX)
# EXPAND_BASE     = $(call CONCAT,$(call EXPAND_PFX,$2) $1 $(call EXPAND_SFX,$2))
# EXPAND_PATH     = $(call PATH_JOIN,$1 $(call EXPAND_BASE,$2,$3))
# EXPAND_DIR_PATH = $(call EXPAND_PATH,$(call EXPAND_DIR,$2),$1,$2)
# EXPAND_MODULES  = $(call EXPAND_VAR,$1 MODULES)
# EXPAND_TARGETS  = $(foreach module,$(call EXPAND_MODULES,$1),$(call EXPAND_VAR,$(module) $1))
# EXPAND_DEP_LINE = $(call EXPAND_VAR,$1 $2): $(call EXPAND_VAR,$1 $2 DEP)
# EXPAND_RECIPE   = $(call EXPAND_VAR,$1 RECIPE)
# EXPAND_RULE     = $(call EXPAND_DEP_LINE,$1,$2)$(CMD_SPACE)$(call EXPAND_RECIPE,$2)


# # placeholders
# # ==============================================================================
# # make target types
# TARGET_TYPES = TRNR_SRC OBJ PIC_OBJ TRNR_OBJ TEST_OBJ BIN TEST_BIN \
#                SHARED STATIC MKDIR_HDR CP_HDR CP_BIN CP_SHARED     \
#                CP_STATIC

# # list of all make targets
# ALL_TARGETS  = $(foreach type,$(TARGET_TYPES),$(call EXPAND_TARGETS,$(type)))

# # make recipes
# TRNR_SRC_RECIPE  = $(RUBY) $(GENERATE_TEST_RUNNER) $$< $$@
# OBJ_RECIPE       = $(CC) $(CFLAGS) -c -o $$@ $$<
# PIC_OBJ_RECIPE   = $(OBJ_RECIPE) $(PIC_FLAG)
# TRNR_OBJ_RECIPE  = $(OBJ_RECIPE)
# TEST_OBJ_RECIPE  = $(OBJ_RECIPE)
# BIN_RECIPE       = $(CC) $(CFLAGS) -o $$@ $$^ $(LFLAGS)
# TEST_BIN_RECIPE  = $(BIN_RECIPE) $(TEST_LFLAGS)
# STATIC_RECIPE    = $(AR) $(ARFLAGS) $$@ $$^
# SHARED_RECIPE    = $(BIN_RECIPE) $(SHARED_FLAG)
# MKDIR_HDR_RECIPE = $(MKDIR) $$@
# CP_HDR_RECIPE    = $(CP) $$< $$@
# CP_BIN_RECIPE    = $(CP_HDR_RECIPE)
# CP_SHARED_RECIPE = $(CP_HDR_RECIPE)
# CP_STATIC_RECIPE = $(CP_HDR_RECIPE)

# # misc
# EMPTY =
# SPACE = $(EMPTY) $(EMPTY)
# TAB   = $(EMPTY)	$(EMPTY)
# define NEWLINE


# endef
# CMD_SPACE  = $(NEWLINE)$(TAB)
# VAR_DELIM  = _
# PATH_DELIM = /


# # parallel config
# # ==============================================================================
# # module name
# PARALLEL = parallel

# # source files
# PARALLEL_SRC      = $(call EXPAND_DIR_PATH,$(PARALLEL),SRC)
# PARALLEL_HDR      = $(call EXPAND_DIR_PATH,$(PARALLEL),HDR)
# PARALLEL_TEST_SRC = $(call EXPAND_DIR_PATH,$(PARALLEL),TEST_SRC)

# # module targets
# PARALLEL_TRNR_SRC  = $(call EXPAND_DIR_PATH,$(PARALLEL),TRNR_SRC)
# PARALLEL_OBJ       = $(call EXPAND_DIR_PATH,$(PARALLEL),OBJ)
# PARALLEL_PIC_OBJ   = $(call EXPAND_DIR_PATH,$(PARALLEL),PIC_OBJ)
# PARALLEL_TRNR_OBJ  = $(call EXPAND_DIR_PATH,$(PARALLEL),TRNR_OBJ)
# PARALLEL_TEST_OBJ  = $(call EXPAND_DIR_PATH,$(PARALLEL),TEST_OBJ)
# PARALLEL_TEST_BIN  = $(call EXPAND_DIR_PATH,$(PARALLEL),TEST_BIN)
# PARALLEL_SHARED    = $(call EXPAND_DIR_PATH,$(PARALLEL),SHARED)
# PARALLEL_STATIC    = $(call EXPAND_DIR_PATH,$(PARALLEL),STATIC)
# PARALLEL_MKDIR_HDR = $(call EXPAND_PATH,$(C_LIBRARY_HEADERS),$(PARALLEL),MKDIR_HDR)
# PARALLEL_CP_HDR    = $(call EXPAND_PATH,$(PARALLEL_MKDIR_HDR),$(PARALLEL),HDR)
# PARALLEL_CP_SHARED = $(call EXPAND_PATH,$(C_SHARED_LIBRARIES),$(PARALLEL),SHARED)
# PARALLEL_CP_STATIC = $(call EXPAND_PATH,$(C_STATIC_LIBRARIES),$(PARALLEL),STATIC)

# # module target dependencies
# PARALLEL_TRNR_SRC_DEP  = $(PARALLEL_TEST_SRC)
# PARALLEL_OBJ_DEP       = $(PARALLEL_SRC) $(PARALLEL_HDR) $(HANDLE_PTHREAD_HDR) $(HANDLE_SEMAPHORE_HDR)
# PARALLEL_PIC_OBJ_DEP   = $(PARALLEL_OBJ_DEP)
# PARALLEL_TRNR_OBJ_DEP  = $(PARALLEL_TRNR_SRC)
# PARALLEL_TEST_OBJ_DEP  = $(PARALLEL_TEST_SRC) $(PARALLEL_OBJ_DEP)
# PARALLEL_TEST_BIN_DEP  = $(PARALLEL_TEST_OBJ) $(PARALLEL_TRNR_OBJ)
# PARALLEL_SHARED_DEP    = $(PARALLEL_PIC_OBJ) $(HANDLE_SEMAPHORE_PIC_OBJ)
# PARALLEL_STATIC_DEP    = $(PARALLEL_OBJ) $(HANDLE_SEMAPHORE_OBJ)
# PARALLEL_MKDIR_HDR_DEP = $(EMPTY)
# PARALLEL_CP_HDR_DEP    = $(PARALLEL_HDR) $(PARALLEL_MKDIR_HDR)
# PARALLEL_CP_SHARED_DEP = $(PARALLEL_SHARED)
# PARALLEL_CP_STATIC_DEP = $(PARALLEL_STATIC)

# # update target groups
# TRNR_SRC_MODULES  += PARALLEL
# OBJ_MODULES       += PARALLEL
# PIC_OBJ_MODULES   += PARALLEL
# TRNR_OBJ_MODULES  += PARALLEL
# TEST_OBJ_MODULES  += PARALLEL
# TEST_BIN_MODULES  += PARALLEL
# SHARED_MODULES    += PARALLEL
# STATIC_MODULES    += PARALLEL
# MKDIR_HDR_MODULES += PARALLEL
# CP_HDR_MODULES    += PARALLEL
# CP_SHARED_MODULES += PARALLEL
# CP_STATIC_MODULES += PARALLEL


# # handle_pthread config
# # ==============================================================================
# # module name
# HANDLE_PTHREAD = handle_pthread

# # source files
# HANDLE_PTHREAD_HDR      = $(call EXPAND_DIR_PATH,$(HANDLE_PTHREAD),HDR)
# HANDLE_PTHREAD_TEST_SRC = $(call EXPAND_DIR_PATH,$(HANDLE_PTHREAD),TEST_SRC)

# # module targets
# HANDLE_PTHREAD_TRNR_SRC  = $(call EXPAND_DIR_PATH,$(HANDLE_PTHREAD),TRNR_SRC)
# HANDLE_PTHREAD_TRNR_OBJ  = $(call EXPAND_DIR_PATH,$(HANDLE_PTHREAD),TRNR_OBJ)
# HANDLE_PTHREAD_TEST_OBJ  = $(call EXPAND_DIR_PATH,$(HANDLE_PTHREAD),TEST_OBJ)
# HANDLE_PTHREAD_TEST_BIN  = $(call EXPAND_DIR_PATH,$(HANDLE_PTHREAD),TEST_BIN)
# HANDLE_PTHREAD_CP_HDR    = $(call EXPAND_PATH,$(PARALLEL_MKDIR_HDR),$(HANDLE_PTHREAD),HDR)

# # module target dependencies
# HANDLE_PTHREAD_TRNR_SRC_DEP  = $(HANDLE_PTHREAD_TEST_SRC)
# HANDLE_PTHREAD_TRNR_OBJ_DEP  = $(HANDLE_PTHREAD_TRNR_SRC)
# HANDLE_PTHREAD_TEST_OBJ_DEP  = $(HANDLE_PTHREAD_TEST_SRC) $(HANDLE_PTHREAD_HDR)
# HANDLE_PTHREAD_TEST_BIN_DEP  = $(HANDLE_PTHREAD_TEST_OBJ) $(HANDLE_PTHREAD_TRNR_OBJ)
# HANDLE_PTHREAD_CP_HDR_DEP    = $(HANDLE_PTHREAD_HDR) $(PARALLEL_MKDIR_HDR)

# # update target groups
# TRNR_SRC_MODULES += HANDLE_PTHREAD
# TRNR_OBJ_MODULES += HANDLE_PTHREAD
# TEST_OBJ_MODULES += HANDLE_PTHREAD
# TEST_BIN_MODULES += HANDLE_PTHREAD
# CP_HDR_MODULES   += HANDLE_PTHREAD


# # handle_semaphore config
# # ==============================================================================
# # module name
# HANDLE_SEMAPHORE = handle_semaphore

# # source files
# HANDLE_SEMAPHORE_SRC      = $(call EXPAND_DIR_PATH,$(HANDLE_SEMAPHORE),SRC)
# HANDLE_SEMAPHORE_HDR      = $(call EXPAND_DIR_PATH,$(HANDLE_SEMAPHORE),HDR)
# HANDLE_SEMAPHORE_TEST_SRC = $(call EXPAND_DIR_PATH,$(HANDLE_SEMAPHORE),TEST_SRC)

# # module targets
# HANDLE_SEMAPHORE_TRNR_SRC = $(call EXPAND_DIR_PATH,$(HANDLE_SEMAPHORE),TRNR_SRC)
# HANDLE_SEMAPHORE_OBJ      = $(call EXPAND_DIR_PATH,$(HANDLE_SEMAPHORE),OBJ)
# HANDLE_SEMAPHORE_PIC_OBJ  = $(call EXPAND_DIR_PATH,$(HANDLE_SEMAPHORE),PIC_OBJ)
# HANDLE_SEMAPHORE_TRNR_OBJ = $(call EXPAND_DIR_PATH,$(HANDLE_SEMAPHORE),TRNR_OBJ)
# HANDLE_SEMAPHORE_TEST_OBJ = $(call EXPAND_DIR_PATH,$(HANDLE_SEMAPHORE),TEST_OBJ)
# HANDLE_SEMAPHORE_TEST_BIN = $(call EXPAND_DIR_PATH,$(HANDLE_SEMAPHORE),TEST_BIN)
# HANDLE_SEMAPHORE_CP_HDR   = $(call EXPAND_PATH,$(PARALLEL_MKDIR_HDR),$(HANDLE_SEMAPHORE),HDR)

# # module target dependencies
# HANDLE_SEMAPHORE_TRNR_SRC_DEP  = $(HANDLE_SEMAPHORE_TEST_SRC)
# HANDLE_SEMAPHORE_OBJ_DEP       = $(HANDLE_SEMAPHORE_SRC) $(HANDLE_SEMAPHORE_HDR)
# HANDLE_SEMAPHORE_PIC_OBJ_DEP   = $(HANDLE_SEMAPHORE_OBJ_DEP)
# HANDLE_SEMAPHORE_TRNR_OBJ_DEP  = $(HANDLE_SEMAPHORE_TRNR_SRC)
# HANDLE_SEMAPHORE_TEST_OBJ_DEP  = $(HANDLE_SEMAPHORE_TEST_SRC) $(HANDLE_SEMAPHORE_OBJ_DEP)
# HANDLE_SEMAPHORE_TEST_BIN_DEP  = $(HANDLE_SEMAPHORE_TEST_OBJ) $(HANDLE_SEMAPHORE_TRNR_OBJ)
# HANDLE_SEMAPHORE_CP_HDR_DEP    = $(HANDLE_SEMAPHORE_HDR) $(PARALLEL_MKDIR_HDR)

# # update target groups
# TRNR_SRC_MODULES += HANDLE_SEMAPHORE
# OBJ_MODULES      += HANDLE_SEMAPHORE
# PIC_OBJ_MODULES  += HANDLE_SEMAPHORE
# TRNR_OBJ_MODULES += HANDLE_SEMAPHORE
# TEST_OBJ_MODULES += HANDLE_SEMAPHORE
# TEST_BIN_MODULES += HANDLE_SEMAPHORE
# CP_HDR_MODULES   += HANDLE_SEMAPHORE


# # make rules
# # ==============================================================================
# # default
# all: $(ALL_TARGETS)

# # unity test runners
# # parallel/test/test_runners/<module>_test_runner.c
# $(foreach module,$(TRNR_SRC_MODULES),$(eval $(call EXPAND_RULE,$(module),TRNR_SRC)))

# # objects
# # parallel/obj/<module>.o
# $(foreach module,$(OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),OBJ)))

# # "position independent code" objects
# # parallel/obj/pic_<module>.o
# $(foreach module,$(PIC_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),PIC_OBJ)))

# # unity test runner objects
# # parallel/obj/<module>_test_runner.o
# $(foreach module,$(TRNR_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),TRNR_OBJ)))

# # unity test objects
# # parallel/obj/<module>_test.o
# $(foreach module,$(TEST_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),TEST_OBJ)))

# # binary files
# # parallel/bin/<module>
# $(foreach module,$(BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),BIN)))

# # test binary files
# # parallel/test/<module>_test
# $(foreach module,$(TEST_BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),TEST_BIN)))

# # dynamic (shared) libraries
# # parallel/shared/lib<module>_shared.so
# $(foreach module,$(SHARED_MODULES),$(eval $(call EXPAND_RULE,$(module),SHARED)))

# # archive (static) libraries
# # parallel/shared/lib<module>_static.a
# $(foreach module,$(STATIC_MODULES),$(eval $(call EXPAND_RULE,$(module),STATIC)))

# # make directories at root of header file include path, 'C_LIBRARY_HEADERS'
# # ~C_LIBRARY_HEADERS/<module>
# $(foreach module,$(CP_HDR_MODULES),$(eval $(call EXPAND_RULE,$(module),MKDIR_HDR)))

# # copy header files to module include path
# # ~C_LIBRARY_HEADERS/<module>/<module>.h
# $(foreach module,$(CP_HDR_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_HDR)))

# # copy binary files to 'USER_BIN'
# # ~USER_BIN/<module>
# $(foreach module,$(CP_BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_BIN)))

# # copy shared library files to 'C_SHARED_LIBRARIES'
# # ~C_SHARED_LIBRARIES/lib<module>_shared.so
# $(foreach module,$(CP_SHARED_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_SHARED)))

# # copy static library files to 'C_STATIC_LIBRARIES'
# # ~C_STATIC_LIBRARIES/lib<module>_static.a
# $(foreach module,$(CP_STATIC_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_STATIC)))

# clean:
# 	$(RM) $(RM_FLAGS) $(ALL_TARGETS)
