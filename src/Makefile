.PHONY: all clean

# TODO:
# 1) fix bheap.c (in process of making more robust, generic)
# 2) complete unit testing
# 3) resolve c-cpp syntax issues for ALL tests

# relative directories
# ==============================================================================
ROOT_DIR = ..
SRC_DIR  = $(ROOT_DIR)/src
OBJ_DIR  = $(ROOT_DIR)/obj
LIB_DIR  = $(ROOT_DIR)/lib
TEST_DIR = $(ROOT_DIR)/tests

# user config
# ==============================================================================
CC      = gcc
CFLAGS  = -g -I$(SRC_DIR) -std=c99 -Wall -D__USE_FIXED_PROTOTYPES__
AR      = ar
ARFLAGS = rcs


# Google Test config
# ==============================================================================
# for 'GTEST_DIR' environment variable
SHELL := /bin/zsh
# Flags passed to the preprocessor.
CPPFLAGS += -isystem $(GTEST_DIR)/include
# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread
# All Google Test headers.
GTEST_HDRS = $(GTEST_DIR)/include/gtest/*.h \
	     $(GTEST_DIR)/include/gtest/internal/*.h
# All Google Test source files.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HDRS)
# Flags for building Google Test object files.
GTEST_OBJ_FLAGS = -I$(GTEST_DIR)
# Flags for building user test object files.
TEST_OBJ_FLAGS  = -I$(SRC_DIR)
# Flags for building user test binary files.
TEST_BIN_FLAGS  = $(TEST_OBJ_FLAGS) -lpthread


# user libraries
# ==============================================================================
# root/lib/utils.a
UTILS_NAME = utils
UTILS_DIR  = $(addprefix $(SRC_DIR)/,   $(UTILS_NAME))
UTILS_SRC  = $(addprefix $(UTILS_DIR)/, $(addsuffix .c, $(UTILS_NAME)))
UTILS_HDR  = $(addprefix $(UTILS_DIR)/, $(addsuffix .h, $(UTILS_NAME)))
UTILS_OBJ  = $(addprefix $(OBJ_DIR)/, 	$(addsuffix .o, $(UTILS_NAME)))
UTILS_LIB  = $(addprefix $(LIB_DIR)/,   $(addsuffix .a, $(addprefix lib, $(UTILS_NAME))))
UTILS_ODEP = $(UTILS_SRC) $(UTILS_HDR)
UTILS_LDEP = $(UTILS_OBJ)

# root/lib/rand.a
RAND_NAME = rand
RAND_DIR  = $(addprefix $(SRC_DIR)/,  $(RAND_NAME))
RAND_SRC  = $(addprefix $(RAND_DIR)/, $(addsuffix .c, $(RAND_NAME)))
RAND_HDR  = $(addprefix $(RAND_DIR)/, $(addsuffix .h, $(RAND_NAME)))
RAND_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(RAND_NAME)))
RAND_LIB  = $(addprefix $(LIB_DIR)/,  $(addsuffix .a, $(addprefix lib, $(RAND_NAME))))
RAND_ODEP = $(RAND_SRC) $(RAND_HDR) $(PCG_HDR)
RAND_LDEP = $(RAND_OBJ) $(PCGB_OBJ)

# root/obj/pcg_basic.o
PCGB_NAME = pcg_basic
PCGB_DIR  = $(RAND_DIR)
PCGB_SRC  = $(addprefix $(PCGB_DIR)/, $(addsuffix .c, $(PCGB_NAME)))
PCGB_HDR  = $(addprefix $(PCGB_DIR)/, $(addsuffix .h, $(PCGB_NAME)))
PCGB_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(PCGB_NAME)))
PCGB_ODEP = $(PCGB_SRC) $(PCGB_HDR)


# root/lib/parallel.a
PARAL_NAME = parallel
PARAL_DIR  = $(addprefix $(SRC_DIR)/,   $(PARAL_NAME))
PARAL_SRC  = $(addprefix $(PARAL_DIR)/, $(addsuffix .c, $(PARAL_NAME)))
PARAL_HDR  = $(addprefix $(PARAL_DIR)/, $(addsuffix .h, $(PARAL_NAME)))
PARAL_OBJ  = $(addprefix $(OBJ_DIR)/,   $(addsuffix .o, $(PARAL_NAME)))
PARAL_LIB  = $(addprefix $(LIB_DIR)/,   $(addsuffix .a, $(addprefix lib, $(PARAL_NAME))))
PARAL_ODEP = $(PARAL_SRC) $(PARAL_HDR)
PARAL_LDEP = $(PARAL_OBJ) $(PCGB_OBJ)

# root/lib/bheap.a
BHEAP_NAME = bheap
BHEAP_DIR  = $(addprefix $(SRC_DIR)/,   $(BHEAP_NAME))
BHEAP_SRC  = $(addprefix $(BHEAP_DIR)/, $(addsuffix .c, $(BHEAP_NAME)))
BHEAP_HDR  = $(addprefix $(BHEAP_DIR)/, $(addsuffix .h, $(BHEAP_NAME)))
BHEAP_OBJ  = $(addprefix $(OBJ_DIR)/, 	$(addsuffix .o, $(BHEAP_NAME)))
BHEAP_LIB  = $(addprefix $(LIB_DIR)/,   $(addsuffix .a, $(addprefix lib, $(BHEAP_NAME))))
BHEAP_ODEP = $(BHEAP_SRC) $(BHEAP_HDR) $(UTILS_HDR)
BHEAP_LDEP = $(BHEAP_OBJ) $(UTILS_OBJ)

# root/lib/big_o.a
BIG_O_NAME = big_o
BIG_O_DIR  = $(addprefix $(SRC_DIR)/,   $(BIG_O_NAME))
BIG_O_SRC  = $(addprefix $(BIG_O_DIR)/, $(addsuffix .c, $(BIG_O_NAME)))
BIG_O_HDR  = $(addprefix $(BIG_O_DIR)/, $(addsuffix .h, $(BIG_O_NAME)))
BIG_O_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(BIG_O_NAME)))
BIG_O_LIB  = $(addprefix $(LIB_DIR)/,  $(addsuffix .a, $(addprefix lib, $(BIG_O_NAME))))
BIG_O_ODEP = $(BIG_O_SRC) $(BIG_O_HDR)
BIG_O_LDEP = $(BIG_O_OBJ)


# tests
# ==============================================================================
# root/obj/gtest-all.a
GTEST_ALL_NAME = gtest-all
GTEST_ALL_SRC  = $(addprefix $(GTEST_DIR)/src/, $(addsuffix .cc, $(GTEST_ALL_NAME)))
GTEST_ALL_OBJ  = $(addprefix $(OBJ_DIR)/,       $(addsuffix .o,  $(GTEST_ALL_NAME)))
GTEST_ALL_LIB  = $(addprefix $(OBJ_DIR)/,       $(addsuffix .a,  $(GTEST_ALL_NAME)))
GTEST_ALL_ODEP = $(GTEST_ALL_SRC) $(GTEST_SRCS_)
GTEST_ALL_LDEP = $(GTEST_ALL_OBJ)

# root/obj/gtest_main.a
GTEST_MAIN_NAME = gtest_main
GTEST_MAIN_SRC  = $(addprefix $(GTEST_DIR)/src/, $(addsuffix .cc, $(GTEST_MAIN_NAME)))
GTEST_MAIN_OBJ  = $(addprefix $(OBJ_DIR)/,       $(addsuffix .o,  $(GTEST_MAIN_NAME)))
GTEST_MAIN_LIB  = $(addprefix $(OBJ_DIR)/,       $(addsuffix .a,  $(GTEST_MAIN_NAME)))
GTEST_MAIN_ODEP = $(GTEST_MAIN_SRC) $(GTEST_SRCS_)
GTEST_MAIN_LDEP = $(GTEST_ALL_OBJ) $(GTEST_MAIN_OBJ)

# root/tests/utils_test
UTILS_TEST_NAME = $(addsuffix _test, $(UTILS_NAME))
UTILS_TEST_SRC  = $(addprefix $(TEST_DIR)/, $(addsuffix .cc, $(UTILS_TEST_NAME)))
UTILS_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,   $(UTILS_TEST_NAME))
UTILS_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(UTILS_TEST_NAME))
UTILS_TEST_ODEP = $(UTILS_TEST_SRC) $(UTILS_SRC) $(GTEST_HDRS)
UTILS_TEST_BDEP = $(UTILS_TEST_OBJ) $(GTEST_MAIN_LIB)

# root/tests/rand_test
RAND_TEST_NAME = $(addsuffix _test, $(RAND_NAME))
RAND_TEST_SRC  = $(addprefix $(TEST_DIR)/, $(addsuffix .cc, $(RAND_TEST_NAME)))
RAND_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,   $(RAND_TEST_NAME))
RAND_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(RAND_TEST_NAME))
RAND_TEST_ODEP = $(RAND_TEST_SRC) $(RAND_SRC) $(GTEST_HDRS)
RAND_TEST_BDEP = $(RAND_TEST_OBJ) $(PCGB_OBJ) $(GTEST_MAIN_LIB)

# root/tests/parallel_test
PARAL_TEST_NAME = $(addsuffix _test, $(PARAL_NAME))
PARAL_TEST_SRC  = $(addprefix $(TEST_DIR)/, $(addsuffix .cc, $(PARAL_TEST_NAME)))
PARAL_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,   $(PARAL_TEST_NAME))
PARAL_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(PARAL_TEST_NAME))
PARAL_TEST_ODEP = $(PARAL_TEST_SRC) $(PARAL_SRC) $(GTEST_HDRS)
PARAL_TEST_BDEP = $(PARAL_TEST_OBJ) $(GTEST_MAIN_LIB)

# root/tests/bheap_test
BHEAP_TEST_NAME = $(addsuffix _test, $(BHEAP_NAME))
BHEAP_TEST_SRC  = $(addprefix $(TEST_DIR)/, $(addsuffix .cc, $(BHEAP_TEST_NAME)))
BHEAP_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,   $(BHEAP_TEST_NAME))
BHEAP_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(BHEAP_TEST_NAME))
BHEAP_TEST_ODEP = $(BHEAP_TEST_SRC) $(BHEAP_SRC) $(GTEST_HDRS)
BHEAP_TEST_BDEP = $(BHEAP_TEST_OBJ) $(GTEST_MAIN_LIB)

# root/tests/big_o_test
BIG_O_TEST_NAME = $(addsuffix _test, $(BIG_O_NAME))
BIG_O_TEST_SRC  = $(addprefix $(TEST_DIR)/, $(addsuffix .cc, $(BIG_O_TEST_NAME)))
BIG_O_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,   $(BIG_O_TEST_NAME))
BIG_O_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(BIG_O_TEST_NAME))
BIG_O_TEST_ODEP = $(BIG_O_TEST_SRC) $(BIG_O_SRC) $(GTEST_HDRS)
BIG_O_TEST_BDEP = $(BIG_O_TEST_OBJ) $(GTEST_MAIN_LIB)


# convenience groupings
USER_ITEMS  = UTILS RAND PARAL BHEAP BIG_O
GTEST_ITEMS = GTEST_ALL GTEST_MAIN
ALL_ITEMS   = $(USER_ITEMS) $(GTEST_ITEMS)

EXPAND_GROUP = $(foreach item, $(patsubst %, %_$1, $2), $($(item)))

ALL_OBJS      = $(call EXPAND_GROUP,OBJ,$(ALL_ITEMS))
ALL_LIBS      = $(call EXPAND_GROUP,LIB,$(ALL_ITEMS))
ALL_TEST_BINS = $(call EXPAND_GROUP,TEST_BIN,$(USER_ITEMS))
# ALL_TARGETS   = $(ALL_OBJS) $(ALL_LIBS) $(ALL_TEST_BINS)
ALL_TARGETS   = $(ALL_OBJS) $(ALL_LIBS)



# make targets
# ==============================================================================
all: $(ALL_TARGETS)

$(UTILS_LIB): $(UTILS_LDEP)
	$(AR) $(ARFLAGS) $@ $^

$(RAND_LIB): $(RAND_LDEP)
	$(AR) $(ARFLAGS) $@ $^

$(PARAL_LIB): $(PARAL_LDEP)
	$(AR) $(ARFLAGS) $@ $^

$(BHEAP_LIB): $(BHEAP_LDEP)
	$(AR) $(ARFLAGS) $@ $^

$(BIG_O_LIB): $(BIG_O_LDEP)
	$(AR) $(ARFLAGS) $@ $^

$(GTEST_ALL_LIB): $(GTEST_ALL_LDEP)
	$(AR) $(ARFLAGS) $@ $^

$(GTEST_MAIN_LIB): $(GTEST_MAIN_LDEP)
	$(AR) $(ARFLAGS) $@ $^

$(UTILS_TEST_BIN): $(UTILS_TEST_BDEP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_BIN_FLAGS) -o $@ $^

$(RAND_TEST_BIN): $(RAND_TEST_BDEP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_BIN_FLAGS) -o $@ $^

$(PARAL_TEST_BIN): $(PARAL_TEST_BDEP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_BIN_FLAGS) -o $@ $^

$(BHEAP_TEST_BIN): $(BHEAP_TEST_BDEP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_BIN_FLAGS) -o $@ $^

$(BIG_O_TEST_BIN): $(BIG_O_TEST_BDEP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_BIN_FLAGS) -o $@ $^

$(UTILS_OBJ): $(UTILS_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PCGB_OBJ): $(PCGB_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(RAND_OBJ): $(RAND_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PARAL_OBJ): $(PARAL_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BHEAP_OBJ): $(BHEAP_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIG_O_OBJ): $(BIG_O_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(GTEST_ALL_OBJ): $(GTEST_ALL_ODEP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(GTEST_OBJ_FLAGS) -c -o $@ $<

$(GTEST_MAIN_OBJ): $(GTEST_MAIN_ODEP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(GTEST_OBJ_FLAGS) -c -o $@ $<

$(UTILS_TEST_OBJ): $(UTILS_TEST_ODEP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_OBJ_FLAGS) -c -o $@ $<

$(RAND_TEST_OBJ): $(RAND_TEST_ODEP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_OBJ_FLAGS) -c -o $@ $<

$(PARAL_TEST_OBJ): $(PARAL_TEST_ODEP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_OBJ_FLAGS) -c -o $@ $<

$(BHEAP_TEST_OBJ): $(BHEAP_TEST_ODEP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_OBJ_FLAGS) -c -o $@ $<

$(BIG_O_TEST_OBJ): $(BIG_O_TEST_OBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_OBJ_FLAGS) -c -o $@ $<

clean:
	$(RM) $(ALL_TARGETS)
