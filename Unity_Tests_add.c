// Unity_Testexample.c : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "mytests.h"

void setUp(void)
{
	
}

void tearDown(void)
{
	// cleanup after each test
}


// Main function. No special functionallity. Only add two printf comands to see if the tool finish correct.
int main()
{
	int feedback = 0;
	printf("Start Test\n");
	// The call of the testfunction
	feedback = test_func_add_main();
	printf("Finished: %i \n", feedback);
}

void test_two_positives()
{
	TEST_ASSERT_EQUAL_INT(8, func_add(3, 5));
}

void test_two_negatives()
{
	TEST_ASSERT_EQUAL_INT(-8, func_add(-3, -5));
}

void test_positive_and_negative()
{
	TEST_ASSERT_EQUAL_INT(2, func_add(5, -3));
}

void test_negative_and_positive()
{
	TEST_ASSERT_EQUAL_INT(-2, func_add(-5, 3));
}

void test_two_zeros()
{
	TEST_ASSERT_EQUAL_INT(0, func_add(0, 0));
}

void test_positive_and_zero()
{
	TEST_ASSERT_EQUAL_INT(5, func_add(5, 0));
}

void test_zero_and_negative()
{
	TEST_ASSERT_EQUAL_INT(-5, func_add(0, -5));
}

void test_opposite_numbers()
{
	TEST_ASSERT_EQUAL_INT(0, func_add(5, -5));
}

void test_max_and_zero()
{
	TEST_ASSERT_EQUAL_INT(INT32_MAX, func_add(INT32_MAX, 0));
}

void test_min_and_zero()
{
	TEST_ASSERT_EQUAL_INT(INT32_MIN, func_add(INT32_MIN, 0));
}

void test_max_minus_one_plus_one()
{
	TEST_ASSERT_EQUAL_INT(INT32_MAX, func_add(INT32_MAX - 1, 1));
}

void test_min_plus_one_minus_one()
{
	TEST_ASSERT_EQUAL_INT(INT32_MIN, func_add(INT32_MIN + 1, -1));
}

void test_not_equal()
{
	TEST_ASSERT_NOT_EQUAL_INT(7, func_add(3, 5));
}

int test_func_add_main()
{
	UNITY_BEGIN();

	//Tests Aufgabe 1

	RUN_TEST(test_two_positives);
	RUN_TEST(test_two_negatives);
	RUN_TEST(test_positive_and_negative);
	RUN_TEST(test_negative_and_positive);
	RUN_TEST(test_two_zeros);
	RUN_TEST(test_positive_and_zero);
	RUN_TEST(test_zero_and_negative);
	RUN_TEST(test_opposite_numbers);
	RUN_TEST(test_max_and_zero);
	RUN_TEST(test_min_and_zero);
	RUN_TEST(test_max_minus_one_plus_one);
	RUN_TEST(test_min_plus_one_minus_one);
	RUN_TEST(test_not_equal);

	return UNITY_END();
}
