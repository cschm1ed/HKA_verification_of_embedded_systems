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

void test_my_strdup()
{
	char *ptr;
	TEST_ASSERT_EQUAL_STRING("TEST", (ptr = my_srtdup("TEST")));
	free(ptr);

	TEST_ASSERT_EQUAL_STRING("EIN SEHR SEHR SEHR SEHR LANGER STRING", (ptr = my_srtdup("EIN SEHR SEHR SEHR SEHR LANGER STRING")));
	free(ptr);
}

void test_divide()
{
	TEST_ASSERT_EQUAL_INT(0, my_divide(1, 0));
}

int test_func_add_main()
{
	UNITY_BEGIN();
	RUN_TEST(test_divide);
	RUN_TEST(test_my_strdup);
	return UNITY_END();
}
