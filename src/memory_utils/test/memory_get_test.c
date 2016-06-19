#include <unity/unity.h>
#include "memory_get.h"

void getUp(void)
{
}

void tearDown(void)
{
}

void test_assign_memory_get(void)
{
	TEST_ASSERT_EQUAL_PTR(&memory_get0,
			      assign_memory_get(0lu));

	TEST_ASSERT_EQUAL_PTR(&memory_get1,
			      assign_memory_get(sizeof(Width1)));

	TEST_ASSERT_EQUAL_PTR(&memory_get2,
			      assign_memory_get(sizeof(Width2)));

	TEST_ASSERT_EQUAL_PTR(&memory_get3,
			      assign_memory_get(sizeof(Width3)));

	TEST_ASSERT_EQUAL_PTR(&memory_get4,
			      assign_memory_get(sizeof(Width4)));

	TEST_ASSERT_EQUAL_PTR(&memory_get5,
			      assign_memory_get(sizeof(Width5)));

	TEST_ASSERT_EQUAL_PTR(&memory_get6,
			      assign_memory_get(sizeof(Width6)));

	TEST_ASSERT_EQUAL_PTR(&memory_get7,
			      assign_memory_get(sizeof(Width7)));

	TEST_ASSERT_EQUAL_PTR(&memory_get8,
			      assign_memory_get(sizeof(Width8)));

	TEST_ASSERT_EQUAL_PTR(&memory_get9,
			      assign_memory_get(sizeof(Width9)));

	TEST_ASSERT_EQUAL_PTR(&memory_get10,
			      assign_memory_get(sizeof(Width10)));

	TEST_ASSERT_EQUAL_PTR(&memory_get11,
			      assign_memory_get(sizeof(Width11)));

	TEST_ASSERT_EQUAL_PTR(&memory_get12,
			      assign_memory_get(sizeof(Width12)));

	TEST_ASSERT_EQUAL_PTR(&memory_get13,
			      assign_memory_get(sizeof(Width13)));

	TEST_ASSERT_EQUAL_PTR(&memory_get14,
			      assign_memory_get(sizeof(Width14)));

	TEST_ASSERT_EQUAL_PTR(&memory_get15,
			      assign_memory_get(sizeof(Width15)));

	TEST_ASSERT_EQUAL_PTR(&memory_get16,
			      assign_memory_get(sizeof(Width16)));

	TEST_ASSERT_NULL(assign_memory_get(WIDTH_MAX_SIZE + 1ul));
}

void test_memory_get_width(void)
{
	struct Name {
		char *first;
		char *middle;
		char *last;
	};

	struct Age {
		uint64_t years;
		uint64_t months;
		uint64_t days;
	};

	struct Height {
		uint64_t feet;
		uint64_t inches;
	};

	struct Weight {
		uint64_t pounds;
		uint64_t ounces;
	};

	typedef struct BigBoy {
		struct Name name;
		struct Age age;
		struct Height height;
		struct Weight weight;
	} BigBoy;


	BigBoy boys[] = {
		[0] = {
			{ "Timmy", "Thomas", "Turner" },
			{ 2u, 11u, 205u },
			{ 2u, 7u },
			{ 30u, 7u }
		},
		[1] = {
			{ "Johnny", "Jordan", "Johanson" },
			{ 7u, 1u, 57u },
			{ 4u, 7u },
			{ 72u, 15u }
		},
		[2] = {
			{ "Bobby", "Bartholomew", "Barker" },
			{ 4u, 0u, 12u },
			{ 3u, 8u },
			{ 45u, 1u }
		},
	};

	BigBoy *boy_act;
	BigBoy *boy_exp;

	for (ptrdiff_t i = 0l; i < 3l; ++i) {

		boy_exp = &boys[i];
		boy_act = (BigBoy *) memory_get_width(&boys[0],
						      i,
						      sizeof(BigBoy));

		TEST_ASSERT_EQUAL_STRING(boy_exp->name.first,
					 boy_act->name.first);
		TEST_ASSERT_EQUAL_STRING(boy_exp->name.middle,
					 boy_act->name.middle);
		TEST_ASSERT_EQUAL_STRING(boy_exp->name.last,
					 boy_act->name.last);

		TEST_ASSERT_EQUAL_INT64(boy_exp->age.years,
					boy_act->age.years);
		TEST_ASSERT_EQUAL_INT64(boy_exp->age.months,
					boy_act->age.months);
		TEST_ASSERT_EQUAL_INT64(boy_exp->age.days,
					boy_act->age.days);

		TEST_ASSERT_EQUAL_INT64(boy_exp->height.feet,
					boy_act->height.feet);
		TEST_ASSERT_EQUAL_INT64(boy_exp->height.inches,
					boy_act->height.inches);

		TEST_ASSERT_EQUAL_INT64(boy_exp->weight.pounds,
					boy_act->weight.pounds);
		TEST_ASSERT_EQUAL_INT64(boy_exp->weight.ounces,
					boy_act->weight.ounces);
	}
}

void test_assign_memory_get_then_get(void)
{
	MemoryGet *get;
	ptrdiff_t i;

	char chars[] = "0123456789";

	get = assign_memory_get(sizeof(char));

	TEST_ASSERT_NOT_NULL(get);

	for (i = (sizeof(chars) / sizeof(char)) - 1l; i >= 0l; --i)
		TEST_ASSERT_EQUAL(chars[i], *((char *) get(&chars[0], i)));


	int32_t ints[] = { INT32_MAX, INT32_MIN, INT32_MAX, INT32_MIN };

	get = assign_memory_get(sizeof(int32_t));

	TEST_ASSERT_NOT_NULL(get);

	for (i = (sizeof(ints) / sizeof(int32_t)) - 1l; i >= 0l; --i)
		TEST_ASSERT_EQUAL_INT32(ints[i], *((int32_t *) get(&ints[0], i)));


	double dbls[] = { 0.0, 1.1, 22.22, 333.333, 4444.4444 };

	get = assign_memory_get(sizeof(double));

	TEST_ASSERT_NOT_NULL(get);

	for (i = (sizeof(dbls) / sizeof(double)) - 1l; i >= 0l; --i)
		TEST_ASSERT_EQUAL_DOUBLE(dbls[i], *((double *) get(&dbls[0], i)));
}
