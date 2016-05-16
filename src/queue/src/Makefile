.PHONY: all clean

# convenience variables
# ==============================================================================
EMPTY =
SPACE = $(EMPTY) $(EMPTY)

# system config
# ==============================================================================
PATH_DELIM = /


# convenience functions
# ==============================================================================
JOIN	  = $(subst $(SPACE),$2,$(strip $1))
CONCAT    = $(call JOIN,$1,$(EMPTY))
PATH_JOIN = $(call JOIN,$1,$(PATH_DELIM))

EXPAND_VAR   = $($(call JOIN,$1 $2,_))
EXPAND_GROUP = $(foreach module,$1,$(call EXPAND_VAR,$(module),$2))




# utility config
# ==============================================================================
CC       = gcc
CFLAGS   = -g -I$(SRC_DIR) -std=c99 -Wall -D__USE_FIXED_PROTOTYPES__
AR       = ar
ARFLAGS  = rcs
LDOPTS   =
SHLFLAGS = -shared -pic
RUBY	 = ruby


# library dependencies
# ==============================================================================
BUILD_LFLAGS = $(call CONCAT,-l $1)

MODULE_LIBS =
TEST_LIBS   = unity

MODULE_LFLAGS = $(call BUILD_LFLAGS,$(MODULE_LIBS))
TEST_LFLAGS   = $(call BUILD_LFLAGS,$(TEST_LIBS))

LDOPTS += $(MODULE_DEP_LIBS)


# unity config
# ==============================================================================
GEN_TRNR_BASE = generate_test_runner.rb
GEN_TRNR_DIR  = $(call PATH_JOIN,$(HOME) my_projects c unity auto)
GEN_TRNR_ABS  = $(call PATH_JOIN,$(GEN_TRNR_DIR) $(GEN_TRNR_BASE))

GENERATE_TRNR = $(RUBY) $(GEN_TRNR_ABS) $1 $2


# directory names
# ==============================================================================
# source files
SRC   = src
# header files
HDR   = $(SRC)
# built object files
OBJ   = obj
# built binary files
BIN   = bin
# built shared library files
SHL   = shared
# built static library files
STL   = static
# test files
TEST  = test
# built test_runner files
TRNR  = test_runners


# directory paths relative project root, $(ROOT_DIR)
# ==============================================================================
ROOT_DIR = ..
SRC_DIR  = $(call PATH_JOIN,$(ROOT_DIR),$(SRC))
HDR_DIR  = $(call PATH_JOIN,$(ROOT_DIR),$(HDR))
OBJ_DIR  = $(call PATH_JOIN,$(ROOT_DIR),$(OBJ))
BIN_DIR  = $(call PATH_JOIN,$(ROOT_DIR),$(BIN))
SHL_DIR  = $(call PATH_JOIN,$(ROOT_DIR),$(SHL))
STL_DIR  = $(call PATH_JOIN,$(ROOT_DIR),$(STL))
TEST_DIR = $(call PATH_JOIN,$(ROOT_DIR),$(TEST))
TRNR_DIR = $(call PATH_JOIN,$(TEST_DIR),$(TRNR))


# file prefixes extensions, prefixes
# ==============================================================================
SRC_EXT  = .c
HDR_EXT  = .h
OBJ_EXT  = .o
BIN_EXT  = $(EMPTY)
SHL_EXT  = .so
STL_EXT  = .a
TEST_EXT = _test.c
TRNR_EXT = _test_runner.c
LIB_PRE  = lib




# builders
# ==============================================================================
EXPAND_DIR = $(call EXPAND_VAR,$1,DIR)
EXPAND_PRE = $(call EXPAND_VAR,$1,PRE)
EXPAND_EXT = $(call EXPAND_VAR,$1,EXT)
EXPAND_BASE = $(call CONCAT,$(call EXPAND_PRE,$2) $1 $(call EXPAND_EXT,$2))
EXPAND_FILE = $(call PATH_JOIN,$(call EXPAND_DIR,$2) $(call EXPAND_BASE,$1,$2))

# BUILD_LIB  = $(call BUILD_FILE,$(LIB_DIR),$(LIB_PRE) $1,$2)


BUILD_SRC  = $(call BUILD_FILE,$(SRC_DIR),$1,$(SRC_EXT))
BUILD_HDR  = $(call BUILD_FILE,$(HDR_DIR),$1,$(HDR_EXT))
BUILD_OBJ  = $(call BUILD_FILE,$(OBJ_DIR),$1,$(OBJ_EXT))
BUILD_BIN  = $(call BUILD_FILE,$(BIN_DIR),$1,$(BIN_EXT))
BUILD_SHL  = $(call BUILD_LIB,$1,$(SHL_EXT))
BUILD_STL  = $(call BUILD_LIB,$1,$(STL_EXT))
BUILD_TEST = $(call BUILD_FILE,$1,$(STL_EXT))

# user targets
# ==============================================================================
# root/bin/queue
QUEUE     = queue

QUEUE_SRC = $(call EXPAND_FILE,$(QUEUE),SRC)
QUEUE_HDR = $(call EXPAND_FILE,$(QUEUE),HDR)
QUEUE_SRC = $(call BUILD_SRC,$(QUEUE))
QUEUE_OBJ = $(call BUILD_OBJ,$(QUEUE))
QUEUE_SRC = $(call BUILD_BIN,$(QUEUE))
QUEUE_SHL = $(call BUILD_SHL,$(QUEUE))
QUEUE_STL = $(call BUILD_STL,$(QUEUE))

QUEUE_SRC  = $(addprefix $(QUEUE_DIR)/, $(addsuffix .c, $(QUEUE)))
QUEUE_HDR  = $(addprefix $(QUEUE_DIR)/, $(addsuffix .h, $(QUEUE)))
QUEUE_OBJ  = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(QUEUE)))
QUEUE_BIN  = $(addprefix $(BIN_DIR)/, $(QUEUE))
QUEUE_ODEP = $(QUEUE_SRC) $(QUEUE_HDR)
QUEUE_BDEP = $(QUEUE_OBJ)

# root/test/queue_test

QUEUE_TEST      = $(addsuffix _test, $(QUEUE))
QUEUE_TRNR      = $(addsuffix _runner, $(QUEUE_TEST))
QUEUE_TEST_DIR  = $(TEST_DIR)
QUEUE_TEST_SRC  = $(addprefix $(QUEUE_TEST_DIR)/, $(addsuffix .c, $(QUEUE_TEST)))
QUEUE_TRNR_SRC  = $(addprefix $(TRNR_DIR)/, $(addsuffix .c, $(QUEUE_TRNR)))
QUEUE_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(QUEUE_TEST)))
QUEUE_TRNR_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(QUEUE_TRNR)))
QUEUE_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(QUEUE_TEST))
QUEUE_TEST_ODEP = $(QUEUE_TEST_SRC) $(QUEUE_ODEP)
QUEUE_TRNR_ODEP = $(QUEUE_TRNR_SRC)
QUEUE_TEST_BDEP = $(QUEUE_TEST_OBJ) $(QUEUE_TRNR_OBJ)


# target groups
# ==============================================================================
MODULES     = QUEUE
SRC_OBJS    = $(call EXPAND_GROUP,OBJ,$(MODULES))
SRC_BINS    = $(call EXPAND_GROUP,BIN,$(MODULES))
TRNR_SRCS   = $(call EXPAND_GROUP,TRNR_SRC,$(MODULES))
TRNR_OBJS   = $(call EXPAND_GROUP,TRNR_OBJ,$(MODULES))
TEST_OBJS   = $(call EXPAND_GROUP,TEST_OBJ,$(MODULES))
TEST_BINS   = $(call EXPAND_GROUP,TEST_BIN,$(MODULES))
ALL_TARGETS = $(SRC_OBJS) $(SRC_BINS) $(TRNR_SRCS) $(TRNR_OBJS) $(TEST_OBJS) $(TEST_BINS)


# make targets
# ==============================================================================
all: $(ALL_TARGETS)


# root/obj/queue.o
$(QUEUE_OBJ): $(QUEUE_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

# root/bin/libqueue.a
$(QUEUE_BIN): $(QUEUE_BDEP)
	$(CC) $(CFLAGS) $(MODULE_LFLAGS) -o $@ $^

$(BHEAP_LIB): $(BHEAP_LDEP)
	$(AR) $(ARFLAGS) $@ $^


# root/test/test_runners/queue_test_runner.c
$(QUEUE_TRNR_SRC):
	$(call GENERATE_TRNR,$(QUEUE_TEST_SRC),$(QUEUE_TRNR_SRC))

# root/obj/queue_test_runner.o
$(QUEUE_TRNR_OBJ): $(QUEUE_TRNR_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

# root/obj/queue_test.o
$(QUEUE_TEST_OBJ): $(QUEUE_TEST_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

# root/test/queue_test
$(QUEUE_TEST_BIN): $(QUEUE_TEST_BDEP)
	$(CC) $(CFLAGS) $(MODULE_LFLAGS) $(TEST_LFLAGS) -o $@ $^


clean:
	$(RM) $(ALL_TARGETS)
