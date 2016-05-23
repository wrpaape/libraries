.PHONY: all clean


# environment config
# ==============================================================================
# USER_BIN           = ~/bin                = export binaries dest dir
# C_LIBRARY_HEADERS  = ~C_LIBRARIES/include = module mkdir (for header) location
# C_SHARED_LIBRARIES = ~C_LIBRARIES/shared  = export shared libraries dest dir
# C_STATIC_LIBRARIES = ~C_LIBRARIES/static  = export static libraries dest dir
# UNITY_SCRIPTS      = ~C_ROOT/unity/auto   = unity scripts folder


# utility config
# ==============================================================================
# utilities
CC    = gcc
AR    = ar
RUBY  = ruby
MKDIR = mkdir
CP    = cp
RM    = rm

# library dependencies
DEP_LIBS      = utils_static
TEST_DEP_LIBS = unity_shared

# flags
C_FLAGS      = -g -I$(HDR_DIR) -std=c99 -Wall -D__USE_FIXED_PROTOTYPES__ -DUNITY_INCLUDE_CONFIG_H
LD_FLAGS     = -L$(C_STATIC_LIBRARIES) -L$(C_SHARED_LIBRARIES) -Wl,-rpath,$(C_SHARED_LIBRARIES)
AR_FLAGS     = rcs
PIC_FLAG     = -fpic
SHARED_FLAG  = -shared
L_FLAGS      = $(call MAP_L_FLAGS,$(DEP_LIBS))
TEST_L_FLAGS = $(call MAP_L_FLAGS,$(TEST_DEP_LIBS))
RM_FLAGS     = -rf

# unity test runner generator script
GENERATE_TEST_RUNNER = $(call PATH_JOIN,$(UNITY_SCRIPTS) generate_test_runner.rb)


# directory config
# ==============================================================================
# header files
HDR      = $(SRC)
# source files
SRC      = src
# main source files
MAIN_SRC = $(SRC)
# all generated object files
OBJ      = obj
# generated module binary files
BIN      = bin
# generated shared library files
SHARED   = shared
# generated static library files
STATIC   = static
# test source and generated test binary files
TEST     = test
# generated test_runner source files
TRNR_SRC = test_runners

# paths relative project root, 'ROOT_DIR'
ROOT_DIR      = ..
HDR_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(HDR))
SRC_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(SRC))
MAIN_SRC_DIR  = $(call PATH_JOIN,$(ROOT_DIR) $(MAIN_SRC))
TEST_SRC_DIR  = $(call PATH_JOIN,$(ROOT_DIR) $(TEST))
TRNR_SRC_DIR  = $(call PATH_JOIN,$(TEST_SRC_DIR) $(TRNR_SRC))
OBJ_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(OBJ))
PIC_OBJ_DIR   = $(OBJ_DIR)
TEST_OBJ_DIR  = $(OBJ_DIR)
TRNR_OBJ_DIR  = $(OBJ_DIR)
BIN_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(BIN))
TEST_BIN_DIR  = $(TEST_SRC_DIR)
SHARED_DIR    = $(call PATH_JOIN,$(ROOT_DIR) $(SHARED))
STATIC_DIR    = $(call PATH_JOIN,$(ROOT_DIR) $(STATIC))


# filename config
# ==============================================================================
LIB_PFX  = lib
MAIN_SFX = _main
TEST_SFX = _test
TRNR_SFX = _test_runner

# prefixes
HDR_PFX       = $(EMPTY)
SRC_PFX       = $(EMPTY)
MAIN_SRC_PFX  = $(EMPTY)
TEST_SRC_PFX  = $(EMPTY)
TRNR_SRC_PFX  = $(EMPTY)
OBJ_PFX       = $(EMPTY)
PIC_OBJ_PFX   = pic_
TRNR_OBJ_PFX  = $(EMPTY)
TEST_OBJ_PFX  = $(EMPTY)
BIN_PFX       = $(EMPTY)
TEST_BIN_PFX  = $(EMPTY)
SHARED_PFX    = $(LIB_PFX)
STATIC_PFX    = $(LIB_PFX)
MKDIR_HDR_PFX = $(EMPTY)

# suffixes (including extensions)
HDR_SFX       = .h
SRC_SFX       = .c
MAIN_SRC_SFX  = $(call CONCAT,$(MAIN_SFX) $(SRC_SFX))
TEST_SRC_SFX  = $(call CONCAT,$(TEST_SFX) $(SRC_SFX))
TRNR_SRC_SFX  = $(call CONCAT,$(TRNR_SFX) $(SRC_SFX))
OBJ_SFX       = .o
PIC_OBJ_SFX   = $(OBJ_SFX)
TEST_OBJ_SFX  = $(call CONCAT,$(TEST_SFX) $(OBJ_SFX))
TRNR_OBJ_SFX  = $(call CONCAT,$(TRNR_SFX) $(OBJ_SFX))
BIN_SFX       = $(EMPTY)
TEST_BIN_SFX  = $(TEST_SFX)
SHARED_SFX    = $(call CONCAT,_ $(SHARED) .so)
STATIC_SFX    = $(call CONCAT,_ $(STATIC) .a)
MKDIR_HDR_SFX = $(EMPTY)


# functions
# ==============================================================================
# string operations
JOIN        = $(subst $(SPACE),$2,$(strip $1))
CONCAT      = $(call JOIN,$1,$(EMPTY))
PATH_JOIN   = $(call JOIN,$1,$(PATH_DELIM))
VAR_JOIN    = $(call JOIN,$1,$(VAR_DELIM))
MAP_L_FLAGS = $(foreach lib,$1,$(call CONCAT,-l $(lib)))

# variable generation, expansion
EXPAND_VAR      = $($(call VAR_JOIN,$1))
EXPAND_DIR      = $(call EXPAND_VAR,$1 DIR)
EXPAND_PFX      = $(call EXPAND_VAR,$1 PFX)
EXPAND_SFX      = $(call EXPAND_VAR,$1 SFX)
EXPAND_BASE     = $(call CONCAT,$(call EXPAND_PFX,$2) $1 $(call EXPAND_SFX,$2))
EXPAND_PATH     = $(call PATH_JOIN,$1 $(call EXPAND_BASE,$2,$3))
EXPAND_DIR_PATH = $(call EXPAND_PATH,$(call EXPAND_DIR,$2),$1,$2)
EXPAND_MODULES  = $(call EXPAND_VAR,$1 MODULES)
EXPAND_TARGETS  = $(foreach module,$(call EXPAND_MODULES,$1),$(call EXPAND_VAR,$(module) $1))
EXPAND_DEP_LINE = $(call EXPAND_VAR,$1 $2): $(call EXPAND_VAR,$1 $2 DEP)
EXPAND_RECIPE   = $(call EXPAND_VAR,$1 RECIPE)
EXPAND_RULE     = $(call EXPAND_DEP_LINE,$1,$2)$(CMD_SPACE)$(call EXPAND_RECIPE,$2)


# placeholders
# ==============================================================================
# make target types
TARGET_TYPES = TRNR_SRC OBJ PIC_OBJ TRNR_OBJ TEST_OBJ BIN TEST_BIN \
               SHARED STATIC MKDIR_HDR CP_HDR CP_BIN CP_SHARED     \
               CP_STATIC

# list of all make targets
ALL_TARGETS  = $(foreach type,$(TARGET_TYPES),$(call EXPAND_TARGETS,$(type)))

# make recipes
TRNR_SRC_RECIPE  = $(RUBY) $(GENERATE_TEST_RUNNER) $$< $$@
OBJ_RECIPE       = $(CC) $(C_FLAGS) -c -o $$@ $$<
PIC_OBJ_RECIPE   = $(OBJ_RECIPE) $(PIC_FLAG)
TRNR_OBJ_RECIPE  = $(OBJ_RECIPE)
TEST_OBJ_RECIPE  = $(OBJ_RECIPE)
BIN_RECIPE       = $(CC) $(C_FLAGS) -o $$@ $$^ $(LD_FLAGS) $(L_FLAGS)
TEST_BIN_RECIPE  = $(BIN_RECIPE) $(TEST_L_FLAGS)
STATIC_RECIPE    = $(AR) $(AR_FLAGS) $$@ $$^
SHARED_RECIPE    = $(BIN_RECIPE) $(SHARED_FLAG)
MKDIR_HDR_RECIPE = $(MKDIR) $$@
CP_HDR_RECIPE    = $(CP) $$< $$@
CP_BIN_RECIPE    = $(CP_HDR_RECIPE)
CP_SHARED_RECIPE = $(CP_HDR_RECIPE)
CP_STATIC_RECIPE = $(CP_HDR_RECIPE)

# misc
EMPTY =
SPACE = $(EMPTY) $(EMPTY)
TAB   = $(EMPTY)	$(EMPTY)
define NEWLINE


endef
CMD_SPACE  = $(NEWLINE)$(TAB)
VAR_DELIM  = _
PATH_DELIM = /


# queue config
# ==============================================================================
# module name
QUEUE = queue

# source files
QUEUE_HDR      = $(call EXPAND_DIR_PATH,$(QUEUE),HDR)
QUEUE_SRC      = $(call EXPAND_DIR_PATH,$(QUEUE),SRC)
QUEUE_TEST_SRC = $(call EXPAND_DIR_PATH,$(QUEUE),TEST_SRC)

# module targets
QUEUE_TRNR_SRC  = $(call EXPAND_DIR_PATH,$(QUEUE),TRNR_SRC)
QUEUE_OBJ       = $(call EXPAND_DIR_PATH,$(QUEUE),OBJ)
QUEUE_PIC_OBJ   = $(call EXPAND_DIR_PATH,$(QUEUE),PIC_OBJ)
QUEUE_TRNR_OBJ  = $(call EXPAND_DIR_PATH,$(QUEUE),TRNR_OBJ)
QUEUE_TEST_OBJ  = $(call EXPAND_DIR_PATH,$(QUEUE),TEST_OBJ)
QUEUE_TEST_BIN  = $(call EXPAND_DIR_PATH,$(QUEUE),TEST_BIN)
QUEUE_SHARED    = $(call EXPAND_DIR_PATH,$(QUEUE),SHARED)
QUEUE_STATIC    = $(call EXPAND_DIR_PATH,$(QUEUE),STATIC)
QUEUE_MKDIR_HDR = $(call EXPAND_PATH,$(C_LIBRARY_HEADERS),$(QUEUE),MKDIR_HDR)
QUEUE_CP_HDR    = $(call EXPAND_PATH,$(QUEUE_MKDIR_HDR),$(QUEUE),HDR)
QUEUE_CP_SHARED = $(call EXPAND_PATH,$(C_SHARED_LIBRARIES),$(QUEUE),SHARED)
QUEUE_CP_STATIC = $(call EXPAND_PATH,$(C_STATIC_LIBRARIES),$(QUEUE),STATIC)

# module target dependencies
QUEUE_TRNR_SRC_DEP  = $(QUEUE_TEST_SRC)
QUEUE_OBJ_DEP       = $(QUEUE_SRC) $(QUEUE_HDR)
QUEUE_PIC_OBJ_DEP   = $(QUEUE_OBJ_DEP)
QUEUE_TRNR_OBJ_DEP  = $(QUEUE_TRNR_SRC)
QUEUE_TEST_OBJ_DEP  = $(QUEUE_TEST_SRC) $(QUEUE_OBJ_DEP)
QUEUE_TEST_BIN_DEP  = $(QUEUE_TEST_OBJ) $(QUEUE_TRNR_OBJ) $(QUEUE_OBJ)
QUEUE_SHARED_DEP    = $(QUEUE_PIC_OBJ)
QUEUE_STATIC_DEP    = $(QUEUE_OBJ)
QUEUE_MKDIR_HDR_DEP = $(EMPTY)
QUEUE_CP_HDR_DEP    = $(QUEUE_HDR) $(QUEUE_MKDIR_HDR)
QUEUE_CP_SHARED_DEP = $(QUEUE_SHARED)
QUEUE_CP_STATIC_DEP = $(QUEUE_STATIC)

# update target groups
TRNR_SRC_MODULES  += QUEUE
OBJ_MODULES       += QUEUE
PIC_OBJ_MODULES   += QUEUE
TRNR_OBJ_MODULES  += QUEUE
TEST_OBJ_MODULES  += QUEUE
TEST_BIN_MODULES  += QUEUE
SHARED_MODULES    += QUEUE
STATIC_MODULES    += QUEUE
MKDIR_HDR_MODULES += QUEUE
CP_HDR_MODULES    += QUEUE
CP_SHARED_MODULES += QUEUE
CP_STATIC_MODULES += QUEUE


# bheap config
# ==============================================================================
# module name
BHEAP = bheap

# source files
BHEAP_SRC      = $(call EXPAND_DIR_PATH,$(BHEAP),SRC)
BHEAP_HDR      = $(call EXPAND_DIR_PATH,$(BHEAP),HDR)
BHEAP_TEST_SRC = $(call EXPAND_DIR_PATH,$(BHEAP),TEST_SRC)

# module targets
BHEAP_TRNR_SRC  = $(call EXPAND_DIR_PATH,$(BHEAP),TRNR_SRC)
BHEAP_OBJ       = $(call EXPAND_DIR_PATH,$(BHEAP),OBJ)
BHEAP_PIC_OBJ   = $(call EXPAND_DIR_PATH,$(BHEAP),PIC_OBJ)
BHEAP_TRNR_OBJ  = $(call EXPAND_DIR_PATH,$(BHEAP),TRNR_OBJ)
BHEAP_TEST_OBJ  = $(call EXPAND_DIR_PATH,$(BHEAP),TEST_OBJ)
BHEAP_TEST_BIN  = $(call EXPAND_DIR_PATH,$(BHEAP),TEST_BIN)
BHEAP_SHARED    = $(call EXPAND_DIR_PATH,$(BHEAP),SHARED)
BHEAP_STATIC    = $(call EXPAND_DIR_PATH,$(BHEAP),STATIC)
BHEAP_CP_HDR    = $(call EXPAND_PATH,$(QUEUE_MKDIR_HDR),$(BHEAP),HDR)
BHEAP_CP_SHARED = $(call EXPAND_PATH,$(C_SHARED_LIBRARIES),$(BHEAP),SHARED)
BHEAP_CP_STATIC = $(call EXPAND_PATH,$(C_STATIC_LIBRARIES),$(BHEAP),STATIC)

# module target dependencies
BHEAP_TRNR_SRC_DEP  = $(BHEAP_TEST_SRC)
BHEAP_OBJ_DEP       = $(BHEAP_SRC) $(BHEAP_HDR)
BHEAP_PIC_OBJ_DEP   = $(BHEAP_OBJ_DEP)
BHEAP_TRNR_OBJ_DEP  = $(BHEAP_TRNR_SRC)
BHEAP_TEST_OBJ_DEP  = $(BHEAP_TEST_SRC) $(BHEAP_OBJ_DEP)
BHEAP_TEST_BIN_DEP  = $(BHEAP_TEST_OBJ) $(BHEAP_TRNR_OBJ) $(BHEAP_OBJ)
BHEAP_SHARED_DEP    = $(BHEAP_PIC_OBJ)
BHEAP_STATIC_DEP    = $(BHEAP_OBJ)
BHEAP_CP_HDR_DEP    = $(BHEAP_HDR) $(QUEUE_MKDIR_HDR)
BHEAP_CP_SHARED_DEP = $(BHEAP_SHARED)
BHEAP_CP_STATIC_DEP = $(BHEAP_STATIC)

# update target groups
TRNR_SRC_MODULES  += BHEAP
OBJ_MODULES       += BHEAP
PIC_OBJ_MODULES   += BHEAP
TRNR_OBJ_MODULES  += BHEAP
TEST_OBJ_MODULES  += BHEAP
TEST_BIN_MODULES  += BHEAP
SHARED_MODULES    += BHEAP
STATIC_MODULES    += BHEAP
CP_HDR_MODULES    += BHEAP
CP_SHARED_MODULES += BHEAP
CP_STATIC_MODULES += BHEAP


# make commands
# ==============================================================================
# rules
all: $(ALL_TARGETS)

# unity test runners
# queue/test/test_runners/<module>_test_runner.c
$(foreach module,$(TRNR_SRC_MODULES),$(eval $(call EXPAND_RULE,$(module),TRNR_SRC)))

# objects
# queue/obj/<module>.o
$(foreach module,$(OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),OBJ)))

# "position independent code" objects
# queue/obj/pic_<module>.o
$(foreach module,$(PIC_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),PIC_OBJ)))

# unity test runner objects
# queue/obj/<module>_test_runner.o
$(foreach module,$(TRNR_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),TRNR_OBJ)))

# unity test objects
# queue/obj/<module>_test.o
$(foreach module,$(TEST_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),TEST_OBJ)))

# binary files
# queue/bin/<module>
$(foreach module,$(BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),BIN)))

# test binary files
# queue/test/<module>_test
$(foreach module,$(TEST_BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),TEST_BIN)))

# dynamic (shared) libraries
# queue/shared/lib<module>_shared.so
$(foreach module,$(SHARED_MODULES),$(eval $(call EXPAND_RULE,$(module),SHARED)))

# archive (static) libraries
# queue/shared/lib<module>_static.a
$(foreach module,$(STATIC_MODULES),$(eval $(call EXPAND_RULE,$(module),STATIC)))

# make directories at root of header file include path, 'C_LIBRARY_HEADERS'
# ~C_LIBRARY_HEADERS/<module>
$(foreach module,$(MKDIR_HDR_MODULES),$(eval $(call EXPAND_RULE,$(module),MKDIR_HDR)))

# copy header files to module include path
# ~C_LIBRARY_HEADERS/<module>/<module>.h
$(foreach module,$(CP_HDR_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_HDR)))

# copy binary files to 'USER_BIN'
# ~USER_BIN/<module>
$(foreach module,$(CP_BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_BIN)))

# copy shared library files to 'C_SHARED_LIBRARIES'
# ~C_SHARED_LIBRARIES/lib<module>_shared.so
$(foreach module,$(CP_SHARED_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_SHARED)))

# copy static library files to 'C_STATIC_LIBRARIES'
# ~C_STATIC_LIBRARIES/lib<module>_static.a
$(foreach module,$(CP_STATIC_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_STATIC)))

clean:
	$(RM) $(RM_FLAGS) $(ALL_TARGETS)
