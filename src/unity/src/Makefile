
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
DEP_LIBS      =
TEST_DEP_LIBS = unity_shared

# flags
CFLAGS      = -g -I$(HDR_DIR) -std=c99 -Wall -D__USE_FIXED_PROTOTYPES__
ARFLAGS     = rcs
PIC_FLAG    = -fpic
SHARED_FLAG = -shared
LFLAGS      = $(call MAP_LFLAGS,$(DEP_LIBS))
TEST_LFLAGS = $(call MAP_LFLAGS,$(TEST_DEP_LIBS))
RM_FLAGS    = -rf

# unity test runner generator script
GENERATE_TEST_RUNNER = $(call PATH_JOIN,$(UNITY_SCRIPTS) generate_test_runner.rb)


# directory config
# ==============================================================================
# source files
SRC    = src
# header files
HDR    = $(SRC)
# all generated object files
OBJ    = obj
# generated module binary files
BIN    = bin
# generated shared library files
SHARED = shared
# generated static library files
STATIC = static
# test source and generated test binary files
TEST   = test
# generated test_runner source files
TRNR   = test_runners

# paths relative project root, 'ROOT_DIR'
ROOT_DIR      = ..
SRC_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(SRC))
HDR_DIR       = $(call PATH_JOIN,$(ROOT_DIR) $(HDR))
IHDR_DIR      = $(HDR_DIR)
CHDR_DIR      = $(HDR_DIR)
TEST_SRC_DIR  = $(call PATH_JOIN,$(ROOT_DIR) $(TEST))
TRNR_SRC_DIR  = $(call PATH_JOIN,$(TEST_SRC_DIR) $(TRNR))
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
INT_SFX  = _internals
CFG_SFX  = _config
TEST_SFX = _test
TRNR_SFX = _test_runner

# prefixes
SRC_PFX       = $(EMPTY)
HDR_PFX       = $(EMPTY)
IHDR_PFX      = $(HDR_PFX)
CHDR_PFX      = $(HDR_PFX)
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
SRC_SFX       = .c
HDR_SFX       = .h
IHDR_SFX      = $(call CONCAT,$(INT_SFX) $(HDR_SFX))
CHDR_SFX      = $(call CONCAT,$(CFG_SFX) $(HDR_SFX))
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
JOIN       = $(subst $(SPACE),$2,$(strip $1))
CONCAT     = $(call JOIN,$1,$(EMPTY))
PATH_JOIN  = $(call JOIN,$1,$(PATH_DELIM))
VAR_JOIN   = $(call JOIN,$1,$(VAR_DELIM))
MAP_LFLAGS = $(foreach lib,$1,$(call CONCAT,-l $(lib)))

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
# list of all make targets
TARGET_TYPES = TRNR_SRC OBJ PIC_OBJ TRNR_OBJ TEST_OBJ BIN TEST_BIN \
               SHARED STATIC MKDIR_HDR CP_HDR CP_BIN CP_SHARED     \
               CP_STATIC
ALL_TARGETS  = $(foreach type,$(TARGET_TYPES),$(call EXPAND_TARGETS,$(type)))

# make recipes
TRNR_SRC_RECIPE  = $(RUBY) $(GENERATE_TEST_RUNNER) $$< $$@
OBJ_RECIPE       = $(CC) $(CFLAGS) -c -o $$@ $$< $(LFLAGS)
PIC_OBJ_RECIPE   = $(OBJ_RECIPE) $(PIC_FLAG)
TRNR_OBJ_RECIPE  = $(OBJ_RECIPE)
TEST_OBJ_RECIPE  = $(OBJ_RECIPE)
BIN_RECIPE       = $(CC) $(CFLAGS) -o $$@ $$^ $(LFLAGS)
TEST_BIN_RECIPE  = $(BIN_RECIPE) $(TEST_LFLAGS)
STATIC_RECIPE    = $(AR) $(ARFLAGS) $$@ $$^
SHARED_RECIPE    = $(BIN_RECIPE) $(SHARED_FLAG)
MKDIR_HDR_RECIPE = $(MKDIR) $$@
CP_HDR_RECIPE    = $(CP) $$< $$@
CP_IHDR_RECIPE   = $(CP_HDR_RECIPE)
CP_CHDR_RECIPE   = $(CP_HDR_RECIPE)
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


# unity config
# ==============================================================================
# module name
UNITY = unity

# source files
UNITY_SRC      = $(call EXPAND_DIR_PATH,$(UNITY),SRC)
UNITY_HDR      = $(call EXPAND_DIR_PATH,$(UNITY),HDR)
UNITY_IHDR     = $(call EXPAND_DIR_PATH,$(UNITY),IHDR)
UNITY_CHDR     = $(call EXPAND_DIR_PATH,$(UNITY),CHDR)
UNITY_TEST_SRC = $(call EXPAND_DIR_PATH,$(UNITY),TEST_SRC)

# module targets
UNITY_TRNR_SRC  = $(call EXPAND_DIR_PATH,$(UNITY),TRNR_SRC)
UNITY_OBJ       = $(call EXPAND_DIR_PATH,$(UNITY),OBJ)
UNITY_PIC_OBJ   = $(call EXPAND_DIR_PATH,$(UNITY),PIC_OBJ)
UNITY_TRNR_OBJ  = $(call EXPAND_DIR_PATH,$(UNITY),TRNR_OBJ)
UNITY_TEST_OBJ  = $(call EXPAND_DIR_PATH,$(UNITY),TEST_OBJ)
UNITY_BIN       = $(call EXPAND_DIR_PATH,$(UNITY),BIN)
UNITY_TEST_BIN  = $(call EXPAND_DIR_PATH,$(UNITY),TEST_BIN)
UNITY_SHARED    = $(call EXPAND_DIR_PATH,$(UNITY),SHARED)
UNITY_STATIC    = $(call EXPAND_DIR_PATH,$(UNITY),STATIC)
UNITY_MKDIR_HDR = $(call EXPAND_PATH,$(C_LIBRARY_HEADERS),$(UNITY),MKDIR_HDR)
UNITY_CP_HDR    = $(call EXPAND_PATH,$(UNITY_MKDIR_HDR),$(UNITY),HDR)
UNITY_CP_IHDR   = $(call EXPAND_PATH,$(UNITY_MKDIR_HDR),$(UNITY),IHDR)
UNITY_CP_CHDR   = $(call EXPAND_PATH,$(UNITY_MKDIR_HDR),$(UNITY),CHDR)
UNITY_CP_BIN    = $(call EXPAND_PATH,$(USER_BIN),$(UNITY),BIN)
UNITY_CP_SHARED = $(call EXPAND_PATH,$(C_SHARED_LIBRARIES),$(UNITY),SHARED)
UNITY_CP_STATIC = $(call EXPAND_PATH,$(C_STATIC_LIBRARIES),$(UNITY),STATIC)


# module target dependencies
UNITY_TRNR_SRC_DEP  = $(UNITY_TEST_SRC)
UNITY_OBJ_DEP       = $(UNITY_SRC) $(UNITY_CP_HDR) $(UNITY_CP_IHDR) $(UNITY_CP_CHDR)
UNITY_PIC_OBJ_DEP   = $(UNITY_OBJ_DEP)
UNITY_TRNR_OBJ_DEP  = $(UNITY_TRNR_SRC) $(UNITY_CP_SHARED)
UNITY_TEST_OBJ_DEP  = $(UNITY_TEST_SRC) $(UNITY_CP_SHARED) $(UNITY_OBJ_DEP)
UNITY_BIN_DEP       = $(UNITY_OBJ)
UNITY_TEST_BIN_DEP  = $(UNITY_TEST_OBJ) $(UNITY_TRNR_OBJ)
UNITY_SHARED_DEP    = $(UNITY_PIC_OBJ)
UNITY_STATIC_DEP    = $(UNITY_OBJ)
UNITY_MKDIR_HDR_DEP = $(EMPTY)
UNITY_CP_HDR_DEP    = $(UNITY_HDR) $(UNITY_MKDIR_HDR)
UNITY_CP_IHDR_DEP   = $(UNITY_IHDR) $(UNITY_MKDIR_HDR)
UNITY_CP_CHDR_DEP   = $(UNITY_CHDR) $(UNITY_MKDIR_HDR)
UNITY_CP_BIN_DEP    = $(UNITY_BIN)
UNITY_CP_SHARED_DEP = $(UNITY_SHARED)
UNITY_CP_STATIC_DEP = $(UNITY_STATIC)

# update target groups
TRNR_SRC_MODULES  += UNITY
OBJ_MODULES       += UNITY
PIC_OBJ_MODULES   += UNITY
TRNR_OBJ_MODULES  += UNITY
TEST_OBJ_MODULES  += UNITY
TEST_BIN_MODULES  += UNITY
SHARED_MODULES    += UNITY
STATIC_MODULES    += UNITY
MKDIR_HDR_MODULES += UNITY
CP_HDR_MODULES    += UNITY
CP_IHDR_MODULES   += UNITY
CP_CHDR_MODULES   += UNITY
CP_SHARED_MODULES += UNITY
CP_STATIC_MODULES += UNITY


# make commands
# ==============================================================================
# rules
all: $(ALL_TARGETS)

# unity test runners
# unity/test/test_runners/<module>_test_runner.c
$(foreach module,$(TRNR_SRC_MODULES),$(eval $(call EXPAND_RULE,$(module),TRNR_SRC)))

# objects
# unity/obj/<module>.o
$(foreach module,$(OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),OBJ)))

# "position independent code" objects
# unity/obj/pic_<module>.o
$(foreach module,$(PIC_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),PIC_OBJ)))

# unity test runner objects
# unity/obj/<module>_test_runner.o
$(foreach module,$(TRNR_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),TRNR_OBJ)))

# unity test objects
# unity/obj/<module>_test.o
$(foreach module,$(TEST_OBJ_MODULES),$(eval $(call EXPAND_RULE,$(module),TEST_OBJ)))

# binary files
# unity/bin/<module>
$(foreach module,$(BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),BIN)))

# test binary files
# unity/test/<module>_test
$(foreach module,$(TEST_BIN_MODULES),$(eval $(call EXPAND_RULE,$(module),TEST_BIN)))

# dynamic (shared) libraries
# unity/shared/lib<module>_shared.so
$(foreach module,$(SHARED_MODULES),$(eval $(call EXPAND_RULE,$(module),SHARED)))

# archive (static) libraries
# unity/shared/lib<module>_static.a
$(foreach module,$(STATIC_MODULES),$(eval $(call EXPAND_RULE,$(module),STATIC)))

# make directories at root of header file include path, 'C_LIBRARY_HEADERS'
# ~C_LIBRARY_HEADERS/<module>
$(foreach module,$(MKDIR_HDR_MODULES),$(eval $(call EXPAND_RULE,$(module),MKDIR_HDR)))

# copy header files to module include path
# ~C_LIBRARY_HEADERS/<module>/<module>.h
$(foreach module,$(CP_HDR_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_HDR)))

# copy internals header files to module include path
# ~C_LIBRARY_HEADERS/<module>/<module>_internals.h
$(foreach module,$(CP_IHDR_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_IHDR)))

# copy config header files to module include path
# ~C_LIBRARY_HEADERS/<module>/<module>_config.h
$(foreach module,$(CP_IHDR_MODULES),$(eval $(call EXPAND_RULE,$(module),CP_CHDR)))

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
