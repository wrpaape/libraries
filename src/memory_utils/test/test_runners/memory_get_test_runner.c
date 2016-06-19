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
#include "memory_get.h"

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_assign_memory_get(void);
extern void test_memory_get_width(void);
extern void test_assign_memory_get_then_get(void);


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
  UnityBegin("../test/memory_get_test.c");
  RUN_TEST(test_assign_memory_get, 12);
  RUN_TEST(test_memory_get_width, 68);
  RUN_TEST(test_assign_memory_get_then_get, 157);

  return (UnityEnd());
}
