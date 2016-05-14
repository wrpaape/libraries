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
UTILS = utils
UTILS_DIR  = $(addprefix $(SRC_DIR)/,   $(UTILS))
UTILS_SRC  = $(addprefix $(UTILS_DIR)/, $(addsuffix .c, $(UTILS)))
UTILS_HDR  = $(addprefix $(UTILS_DIR)/, $(addsuffix .h, $(UTILS)))
UTILS_OBJ  = $(addprefix $(OBJ_DIR)/, 	$(addsuffix .o, $(UTILS)))
UTILS_LIB  = $(addprefix $(LIB_DIR)/,   $(addsuffix .a, $(addprefix lib, $(UTILS))))
UTILS_ODEP = $(UTILS_SRC) $(UTILS_HDR)
UTILS_LDEP = $(UTILS_OBJ)

# root/lib/rand.a
RAND = rand
RAND_DIR  = $(addprefix $(SRC_DIR)/,  $(RAND))
RAND_SRC  = $(addprefix $(RAND_DIR)/, $(addsuffix .c, $(RAND)))
RAND_HDR  = $(addprefix $(RAND_DIR)/, $(addsuffix .h, $(RAND)))
RAND_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(RAND)))
RAND_LIB  = $(addprefix $(LIB_DIR)/,  $(addsuffix .a, $(addprefix lib, $(RAND))))
RAND_ODEP = $(RAND_SRC) $(RAND_HDR) $(PCG_HDR)
RAND_LDEP = $(RAND_OBJ) $(PCGB_OBJ)

# root/obj/pcg_basic.o
PCGB = pcg_basic
PCGB_DIR  = $(RAND_DIR)
PCGB_SRC  = $(addprefix $(PCGB_DIR)/, $(addsuffix .c, $(PCGB)))
PCGB_HDR  = $(addprefix $(PCGB_DIR)/, $(addsuffix .h, $(PCGB)))
PCGB_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(PCGB)))
PCGB_ODEP = $(PCGB_SRC) $(PCGB_HDR)


# root/lib/parallel.a
PARAL = parallel
PARPT = pthread
PARAL_DIR  = $(addprefix $(SRC_DIR)/,   $(PARAL))
PARAL_SRC  = $(addprefix $(PARAL_DIR)/, $(addsuffix .c, $(PARAL)))
PARAL_HDR  = $(addprefix $(PARAL_DIR)/, $(addsuffix .h, $(PARAL)))
PHNDL_HDR  = $(addprefix $(PARAL_DIR)/, $(addsuffix .h, $(PARPT)))
PARAL_OBJ  = $(addprefix $(OBJ_DIR)/,   $(addsuffix .o, $(PARAL)))
PARAL_LIB  = $(addprefix $(LIB_DIR)/,   $(addsuffix .a, $(addprefix lib, $(PARAL))))
PARAL_ODEP = $(PARAL_SRC) $(PARAL_HDR) $(PHNDL_HDR)
PARAL_LDEP = $(PARAL_OBJ) $(PCGB_OBJ)

# root/lib/bheap.a
BHEAP = bheap
BHEAP_DIR  = $(addprefix $(SRC_DIR)/,   $(BHEAP))
BHEAP_SRC  = $(addprefix $(BHEAP_DIR)/, $(addsuffix .c, $(BHEAP)))
BHEAP_HDR  = $(addprefix $(BHEAP_DIR)/, $(addsuffix .h, $(BHEAP)))
BHEAP_OBJ  = $(addprefix $(OBJ_DIR)/, 	$(addsuffix .o, $(BHEAP)))
BHEAP_LIB  = $(addprefix $(LIB_DIR)/,   $(addsuffix .a, $(addprefix lib, $(BHEAP))))
BHEAP_ODEP = $(BHEAP_SRC) $(BHEAP_HDR) $(UTILS_HDR)
BHEAP_LDEP = $(BHEAP_OBJ) $(UTILS_OBJ)

# root/lib/big_o.a
BIG_O = big_o
BIG_O_DIR  = $(addprefix $(SRC_DIR)/,   $(BIG_O))
BIG_O_SRC  = $(addprefix $(BIG_O_DIR)/, $(addsuffix .c, $(BIG_O)))
BIG_O_HDR  = $(addprefix $(BIG_O_DIR)/, $(addsuffix .h, $(BIG_O)))
BIG_O_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(BIG_O)))
BIG_O_LIB  = $(addprefix $(LIB_DIR)/,  $(addsuffix .a, $(addprefix lib, $(BIG_O))))
BIG_O_ODEP = $(BIG_O_SRC) $(BIG_O_HDR)
BIG_O_LDEP = $(BIG_O_OBJ)

# root/lib/unity.a
UNITY = unity
UNITY_DIR  = $(addprefix $(SRC_DIR)/,   $(UNITY))
UNITY_SRC  = $(addprefix $(UNITY_DIR)/, $(addsuffix .c, $(UNITY)))
UNITY_HDR  = $(addprefix $(UNITY_DIR)/, $(addsuffix .h, $(UNITY)))
UNTIY_IHDR = $(patsubst %.h, %_internals.h, $(UNITY_HDR))
UNITY_CHDR = $(patsubst %.h, %_config.h,    $(UNITY_HDR))
UNITY_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(UNITY)))
UNITY_LIB  = $(addprefix $(LIB_DIR)/,  $(addsuffix .a, $(addprefix lib, $(UNITY))))
UNITY_ODEP = $(UNITY_SRC) $(UNITY_HDR) $(UNITY_IHDR) $(UNITY_CHDR)
UNITY_LDEP = $(UNITY_OBJ)

# root/lib/ascii.a
ASCII	   = ascii
ASCII_DIR  = $(addprefix $(SRC_DIR)/,   $(ASCII))
ASCII_SRC  = $(addprefix $(ASCII_DIR)/, $(addsuffix .c, $(ASCII)))
ASCII_HDR  = $(addprefix $(ASCII_DIR)/, $(addsuffix .h, $(ASCII)))
ASCII_LHDR = $(patsubst %.h, %_lookup.h, $(ASCII_HDR))
ASCII_OBJ  = $(addprefix $(OBJ_DIR)/,  $(addsuffix .o, $(ASCII)))
ASCII_LIB  = $(addprefix $(LIB_DIR)/,  $(addsuffix .a, $(addprefix lib, $(ASCII))))
ASCII_ODEP = $(ASCII_SRC) $(ASCII_HDR) $(ASCII_LHDR)
ASCII_LDEP = $(ASCII_OBJ)


# tests
# ==============================================================================
# root/obj/gtest-all.a
GTEST_ALL = gtest-all
GTEST_ALL_SRC  = $(addprefix $(GTEST_DIR)/src/, $(addsuffix .cc, $(GTEST_ALL)))
GTEST_ALL_OBJ  = $(addprefix $(OBJ_DIR)/,       $(addsuffix .o,  $(GTEST_ALL)))
GTEST_ALL_LIB  = $(addprefix $(OBJ_DIR)/,       $(addsuffix .a,  $(GTEST_ALL)))
GTEST_ALL_ODEP = $(GTEST_ALL_SRC) $(GTEST_SRCS_)
GTEST_ALL_LDEP = $(GTEST_ALL_OBJ)

# root/obj/gtest_main.a
GTEST_MAIN = gtest_main
GTEST_MAIN_SRC  = $(addprefix $(GTEST_DIR)/src/, $(addsuffix .cc, $(GTEST_MAIN)))
GTEST_MAIN_OBJ  = $(addprefix $(OBJ_DIR)/,       $(addsuffix .o,  $(GTEST_MAIN)))
GTEST_MAIN_LIB  = $(addprefix $(OBJ_DIR)/,       $(addsuffix .a,  $(GTEST_MAIN)))
GTEST_MAIN_ODEP = $(GTEST_MAIN_SRC) $(GTEST_SRCS_)
GTEST_MAIN_LDEP = $(GTEST_ALL_OBJ) $(GTEST_MAIN_OBJ)

# root/tests/utils_test
UTILS_TEST = $(addsuffix _test, $(UTILS))
UTILS_TEST_SRC  = $(addprefix $(TEST_DIR)/, $(addsuffix .cc, $(UTILS_TEST)))
UTILS_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,  $(UTILS_TEST))
UTILS_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(UTILS_TEST))
UTILS_TEST_ODEP = $(UTILS_TEST_SRC) $(UTILS_SRC) $(GTEST_HDRS)
UTILS_TEST_BDEP = $(UTILS_TEST_OBJ) $(GTEST_MAIN_LIB)

# root/tests/rand_test
RAND_TEST = $(addsuffix _test, $(RAND))
RAND_TEST_SRC  = $(addprefix $(TEST_DIR)/, $(addsuffix .cc, $(RAND_TEST)))
RAND_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,  $(RAND_TEST))
RAND_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(RAND_TEST))
RAND_TEST_ODEP = $(RAND_TEST_SRC) $(RAND_SRC) $(GTEST_HDRS)
RAND_TEST_BDEP = $(RAND_TEST_OBJ) $(PCGB_OBJ) $(GTEST_MAIN_LIB)

# root/tests/parallel_test
PARAL_TEST = $(addsuffix _test, $(PARAL))
PARAL_TEST_SRC  = $(addprefix $(TEST_DIR)/, $(addsuffix .cc, $(PARAL_TEST)))
PARAL_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,  $(PARAL_TEST))
PARAL_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(PARAL_TEST))
PARAL_TEST_ODEP = $(PARAL_TEST_SRC) $(PARAL_SRC) $(GTEST_HDRS)
PARAL_TEST_BDEP = $(PARAL_TEST_OBJ) $(GTEST_MAIN_LIB)

# root/tests/bheap_test
BHEAP_TEST = $(addsuffix _test, $(BHEAP))
BHEAP_TEST_SRC  = $(addprefix $(TEST_DIR)/, $(addsuffix .cc, $(BHEAP_TEST)))
BHEAP_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,  $(BHEAP_TEST))
BHEAP_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(BHEAP_TEST))
BHEAP_TEST_ODEP = $(BHEAP_TEST_SRC) $(BHEAP_SRC) $(GTEST_HDRS)
BHEAP_TEST_BDEP = $(BHEAP_TEST_OBJ) $(GTEST_MAIN_LIB)

# root/tests/big_o_test
BIG_O_TEST = $(addsuffix _test, $(BIG_O))
BIG_O_TEST_SRC  = $(addprefix $(TEST_DIR)/, $(addsuffix .cc, $(BIG_O_TEST)))
BIG_O_TEST_OBJ  = $(addprefix $(OBJ_DIR)/,  $(BIG_O_TEST))
BIG_O_TEST_BIN  = $(addprefix $(TEST_DIR)/, $(BIG_O_TEST))
BIG_O_TEST_ODEP = $(BIG_O_TEST_SRC) $(BIG_O_SRC) $(GTEST_HDRS)
BIG_O_TEST_BDEP = $(BIG_O_TEST_OBJ) $(GTEST_MAIN_LIB)


# convenience groupings
# USER_ITEMS  = UTILS RAND PARAL BHEAP BIG_O
USER_ITEMS  = UTILS RAND PARAL BHEAP UNITY ASCII
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

$(UNITY_LIB): $(UNITY_LDEP)
	$(AR) $(ARFLAGS) $@ $^

$(ASCII_LIB): $(ASCII_LDEP)
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

$(UNITY_OBJ): $(UNITY_ODEP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(ASCII_OBJ): $(ASCII_ODEP)
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
