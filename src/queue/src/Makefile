.PHONY: all clean

# directory names
# ==============================================================================
# source files
SRC   = src
# header files
HDR   = $(SRC)
# all built object files
OBJ   = obj
# built module binary files
BIN   = bin
# built shared library files
SHL   = shared
# built static library files
STL   = static
# test source and built test binary files
TEST  = test
# built test_runner source files
TRNR  = test_runners


# directory paths relative project root, $(ROOT_DIR)
# ==============================================================================
ROOT_DIR     = ..
SRC_DIR      = $(call PATH_JOIN,$(ROOT_DIR) $(SRC))
HDR_DIR      = $(call PATH_JOIN,$(ROOT_DIR) $(HDR))
TEST_SRC_DIR = $(call PATH_JOIN,$(ROOT_DIR) $(TEST))
TRNR_SRC_DIR = $(call PATH_JOIN,$(TEST_SRC_DIR) $(TRNR))
OBJ_DIR	     = $(call PATH_JOIN,$(ROOT_DIR) $(OBJ))
PIC_OBJ_DIR  = $(OBJ_DIR)
TEST_OBJ_DIR = $(OBJ_DIR)
TRNR_OBJ_DIR = $(OBJ_DIR)
BIN_DIR	     = $(call PATH_JOIN,$(ROOT_DIR) $(BIN))
TEST_BIN_DIR = $(TEST_SRC_DIR)
SHL_DIR	     = $(call PATH_JOIN,$(ROOT_DIR) $(SHL))
STL_DIR	     = $(call PATH_JOIN,$(ROOT_DIR) $(STL))

# file prefixes, extensions
# ==============================================================================
LIB_PRE  = lib
TEST_EXT = _test

SRC_PRE      = $(EMPTY)
HDR_PRE      = $(EMPTY)
TEST_PRE     = $(EMPTY)
TRNR_PRE     = $(EMPTY)
OBJ_PRE      = $(EMPTY)
PIC_OBJ_PRE  = pic_
BIN_PRE	     = $(EMPTY)
TEST_BIN_PRE = $(EMPTY)
SHL_PRE      = $(LIB_PRE)
STL_PRE      = $(LIB_PRE)

TEST_BIN_EXT = $(TEST_EXT)
SRC_EXT      = .c
HDR_EXT      = .h
TEST_SRC_EXT = $(call CONCAT, $(TEST_EXT) $(SRC_EXT))
TRNR_SRC_EXT = $(call CONCAT, $(TEST_EXT) _runner $(SRC_EXT))
OBJ_EXT      = .o
PIC_OBJ_EXT  = $(OBJ_EXT)
BIN_EXT	     = $(EMPTY)
SHL_EXT      = .so
STL_EXT      = .a


# utility config
# ==============================================================================
CC       = gcc
CFLAGS   = -g -I$(HDR_DIR) -std=c99 -Wall -D__USE_FIXED_PROTOTYPES__
AR       = ar
ARFLAGS  = rcs
PIC_FLAG = -fpic
SHL_FLAG = -shared
RUBY	 = ruby

# unity config
# ==============================================================================
GEN_TRNR_BASE = generate_test_runner.rb
GEN_TRNR_DIR  = $(call PATH_JOIN,$(HOME) my_projects c unity auto)
GEN_TRNR_ABS  = $(call PATH_JOIN,$(GEN_TRNR_DIR) $(GEN_TRNR_BASE))

# make recipes
# ==============================================================================
TRNR_SRC_RECIPE	= $(RUBY) $(GEN_TRNR_ABS) $< $@
OBJ_RECIPE 	= $(CC) $(CFLAGS) -c -o $@ $<
PIC_OBJ_RECIPE  = $(OBJ_RECIPE) $(PIC_FLAG)
TRNR_OBJ_RECIPE = $(OBJ_RECIPE)
TEST_OBJ_RECIPE = $(OBJ_RECIPE)
BIN_RECIPE 	= $(CC) $(CFLAGS) -o $@ $^ $(DEP_LFLAGS)
TEST_BIN_RECIPE = $(BIN_RECIPE) $(TEST_LFLAGS)
STL_RECIPE 	= $(AR) $(ARFLAGS) $@ $^
SHL_RECIPE 	= $(BIN_RECIPE) $(SHL_FLAG)

# convenience variables
# ==============================================================================
EMPTY =
SPACE = $(EMPTY) $(EMPTY)
VAR_DELIM = _
PATH_DELIM = /

# convenience functions
# ==============================================================================
JOIN	  = $(subst $(SPACE),$2,$(strip $1))
CONCAT    = $(call JOIN,$1,$(EMPTY))
PATH_JOIN = $(call JOIN,$1,$(PATH_DELIM))
VAR_JOIN  = $(call JOIN,$1,$(VAR_DELIM))



# library dependencies
# ==============================================================================
BUILD_LFLAGS = $(call CONCAT,-l $1)

DEP_LIBS  =
TEST_LIBS = unity

DEP_LFLAGS  = $(call BUILD_LFLAGS,$(DEP_LIBS))
TEST_LFLAGS = $(call BUILD_LFLAGS,$(TEST_LIBS))



# expansion functions
# ==============================================================================
EXPAND_VAR   	= $($(call VAR_JOIN,$1))
EXPAND_GROUP	= $(foreach module,$1,$(call EXPAND_VAR,$(module) $2))
EXPAND_DIR 	= $(call EXPAND_VAR,$1 DIR)
EXPAND_PRE 	= $(call EXPAND_VAR,$1 PRE)
EXPAND_EXT 	= $(call EXPAND_VAR,$1 EXT)
EXPAND_BASE	= $(call CONCAT,$(call EXPAND_PRE,$2) $1 $(call EXPAND_EXT,$2))
EXPAND_PATH	= $(call PATH_JOIN,$(call EXPAND_DIR,$2) $(call EXPAND_BASE,$1,$2))
EXPAND_DEP_LINE = $(call EXPAND_VAR,$1 $2): $(call EXPAND_VAR,$1 $2 DEP)
define MAKE_TARGET =
$(call EXPAND_DEP_LINE,$1,$2)
	$(call EXPAND_VAR,$2 RECIPE)
endef



# make queue
# ==============================================================================
QUEUE          = queue

# source files
QUEUE_SRC      = $(call EXPAND_PATH,$(QUEUE),SRC)
QUEUE_HDR      = $(call EXPAND_PATH,$(QUEUE),HDR)
QUEUE_TEST_SRC = $(call EXPAND_PATH,$(QUEUE),TEST_SRC)

# make targets
QUEUE_TRNR_SRC = $(call EXPAND_PATH,$(QUEUE),TRNR_SRC)
QUEUE_OBJ      = $(call EXPAND_PATH,$(QUEUE),OBJ)
QUEUE_PIC_OBJ  = $(call EXPAND_PATH,$(QUEUE),PIC_OBJ)
QUEUE_TEST_OBJ = $(call EXPAND_PATH,$(QUEUE),TEST_OBJ)
QUEUE_TRNR_OBJ = $(call EXPAND_PATH,$(QUEUE),TRNR_OBJ)
QUEUE_BIN      = $(call EXPAND_PATH,$(QUEUE),BIN)
QUEUE_TEST_BIN = $(call EXPAND_PATH,$(QUEUE),TEST_BIN)
QUEUE_SHL      = $(call EXPAND_PATH,$(QUEUE),SHL)
QUEUE_STL      = $(call EXPAND_PATH,$(QUEUE),STL)

# make dependencies
QUEUE_TRNR_SRC_DEP = $(QUEUE_TEST_SRC)
QUEUE_OBJ_DEP      = $(QUEUE_SRC) $(QUEUE_HDR)
QUEUE_PIC_OBJ_DEP  = $(QUEUE_OBJ_DEP)
QUEUE_TRNR_OBJ_DEP = $(QUEUE_TRNR_SRC)
QUEUE_TEST_OBJ_DEP = $(QUEUE_TEST_SRC) $(QUEUE_OBJ_DEP)
QUEUE_BIN_DEP	   = $(QUEUE_OBJ)
QUEUE_TEST_BIN_DEP = $(QUEUE_TEST_OBJ) $(QUEUE_TRNR_OBJ)
QUEUE_SHL_DEP	   = $(QUEUE_PIC_OBJ)
QUEUE_STL_DEP	   = $(QUEUE_OBJ)

# update target groups
TRNR_SRC_MODULES += QUEUE
OBJ_MODULES      += QUEUE
PIC_OBJ_MODULES  += QUEUE
TRNR_OBJ_MODULES += QUEUE
TEST_OBJ_MODULES += QUEUE
BIN_MODULES      += QUEUE
TEST_BIN_MODULES += QUEUE
SHL_MODULES      += QUEUE
STL_MODULES      += QUEUE

TARGET_TYPES   = TRNR_SRC OBJ PIC_OBJ TRNR_OBJ TEST_OBJ BIN TEST_BIN SHL STL
EXPAND_MODULES = $(call EXPAND_VAR,$1 MODULES)
EXPAND_TARGETS = $(foreach module,$(call EXPAND_MODULES,$1),$(call EXPAND_VAR,$(module) $1))
ALL_TARGETS    = $(foreach type,$(TARGET_TYPES),$(call EXPAND_TARGETS,$(type)))

$(info $(ALL_TARGETS))
$(info $(ALL_TARGETS))
$(info $(ALL_TARGETS))
$(info $(ALL_TARGETS))


# make targets
# ==============================================================================
all: $(ALL_TARGETS)

# unity test runners
# root/test/test_runners/*_test_runner.c
$(foreach module,TRNR_SRC_TARGETS,$(eval $(call MAKE_TARGET,$(module),TRNR_SRC)))

# module objects
# root/obj/*.o
$(foreach module,OBJ_TARGETS,$(eval $(call MAKE_TARGET,$(module),OBJ)))

# module objects
# root/obj/pic_*.o
$(foreach module,PIC_OBJ_TARGETS,$(eval $(call MAKE_TARGET,$(module),PIC_OBJ)))

clean:
	$(RM) $(ALL_TARGETS)
