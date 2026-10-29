#include "mytests.h"

int main()
{
	int feedback = 0;
	printf("Start Test\n");
	// The call of the testfunction
	feedback = test_func_add_main();
	printf("Finished: %i \n", feedback);
}

void setUp(void)
{

}

void tearDown(void)
{

}

void test_copy_short_string()
{
	char *ptr;
	TEST_ASSERT_EQUAL_STRING("TEST", (ptr = my_srtdup("TEST")));
	free(ptr);
}

void test_copy_long_string()
{
	char *ptr;
	TEST_ASSERT_EQUAL_STRING("EIN SEHR SEHR SEHR SEHR LANGER STRING", (ptr = my_srtdup("EIN SEHR SEHR SEHR SEHR LANGER STRING")));
	free(ptr);
}

void test_copy_empty_string()
{
	char *ptr;
	TEST_ASSERT_EQUAL_STRING("", (ptr = my_srtdup("")));
	free(ptr);
}

void test_divide_positives()
{
	TEST_ASSERT_EQUAL_INT(3, my_divide(12, 4));
}

void test_divide_negatives()
{
	TEST_ASSERT_EQUAL_INT(3, my_divide(-12, -4));
}


void test_divide_by_zero()
{
	TEST_ASSERT_EQUAL_INT(0, my_divide(1, 0));
}


int test_func_add_main()
{
	UNITY_BEGIN();
	RUN_TEST(test_divide_by_zero);
	RUN_TEST(test_divide_positives);
	RUN_TEST(test_divide_negatives);

	RUN_TEST(test_copy_short_string);
	RUN_TEST(test_copy_empty_string);
	RUN_TEST(test_copy_long_string);
	return UNITY_END();
}
