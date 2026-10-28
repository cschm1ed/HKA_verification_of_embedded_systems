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

void test_function_testSort()
{
	int *ptr;

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){3, 2, 1}), (ptr = func_sortThreeNumbers(3, 2, 1)), 3);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){2, 1, 0}), (ptr = func_sortThreeNumbers(2, 2, 1)), 3);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){3, 2, -1}), (ptr = func_sortThreeNumbers(2, -1, 3)), 3);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){INT_MAX, 0, INT_MIN}), (ptr = func_sortThreeNumbers(INT_MIN, 0, INT_MAX)), 3);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){7, 4, 0}), (ptr = func_sortThreeNumbers(4, 4, 7)), 3);
	free(ptr);
}

void test_function_testSort_and_State() {
	int *ptr;
	int a_smallest, b_smallest, doublet_exists;

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){1, 2, 3}), (ptr = func_sortThreeNumbers_state(3, 2, 1, &a_smallest, &b_smallest, &doublet_exists)), 3);
	TEST_ASSERT_EQUAL_INT(False, a_smallest);
	TEST_ASSERT_EQUAL_INT(False, b_smallest);
	TEST_ASSERT_EQUAL_INT(False, doublet_exists);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){1, 2, 0}), (ptr = func_sortThreeNumbers_state(2, 2, 1, &a_smallest, &b_smallest, &doublet_exists)), 3);
	TEST_ASSERT_EQUAL_INT(False, a_smallest);
	TEST_ASSERT_EQUAL_INT(False, b_smallest);
	TEST_ASSERT_EQUAL_INT(True, doublet_exists);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){1, 2, 3}), (ptr = func_sortThreeNumbers_state(1, 3, 2, &a_smallest, &b_smallest, &doublet_exists)), 3);
	TEST_ASSERT_EQUAL_INT(True, a_smallest);
	TEST_ASSERT_EQUAL_INT(False, b_smallest);
	TEST_ASSERT_EQUAL_INT(False, doublet_exists);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){1, 2, 0}), (ptr = func_sortThreeNumbers_state(2, 2, 1, &a_smallest, &b_smallest, &doublet_exists)), 3);
	TEST_ASSERT_EQUAL_INT(False, a_smallest);
	TEST_ASSERT_EQUAL_INT(True, b_smallest);
	TEST_ASSERT_EQUAL_INT(True, doublet_exists);
	free(ptr);
}

int test_func_add_main()
{
	UNITY_BEGIN();
	RUN_TEST(test_function_testSort);
	RUN_TEST(test_function_testSort_and_State);
	return UNITY_END();
}
