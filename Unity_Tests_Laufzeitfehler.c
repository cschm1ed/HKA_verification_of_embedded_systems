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

void test_divide()
{
	TEST_ASSERT_EQUAL_INT(0, my_divide(1, 0));
}

int test_func_add_main()
{
	UNITY_BEGIN();
	RUN_TEST(test_divide);
	return UNITY_END();
}
