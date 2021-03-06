/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include <unity/unity.h>
#include <setjmp.h>
#include <stdio.h>
#include "memory_swap.h"

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_VAR_SWAP(void);
extern void test_EL_SWAP_char(void);
extern void test_EL_SWAP_int64(void);
extern void test_memory_swap_width_basic_primitive_types(void);
extern void test_memory_swap_string(void);
extern void test_memory_swap_pointers(void);
extern void test_assign_memory_swap(void);
extern void test_assign_memory_swap_then_swap(void);


//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  UnityBegin("../test/memory_swap_test.c");
  RUN_TEST(test_VAR_SWAP, 12);
  RUN_TEST(test_EL_SWAP_char, 28);
  RUN_TEST(test_EL_SWAP_int64, 41);
  RUN_TEST(test_memory_swap_width_basic_primitive_types, 56);
  RUN_TEST(test_memory_swap_string, 84);
  RUN_TEST(test_memory_swap_pointers, 95);
  RUN_TEST(test_assign_memory_swap, 118);
  RUN_TEST(test_assign_memory_swap_then_swap, 174);

  return (UnityEnd());
}
