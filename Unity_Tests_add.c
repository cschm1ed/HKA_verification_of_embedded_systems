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

void test_function_chatGptTests()
{
	TEST_ASSERT_EQUAL_INT(8, func_add(3, 5));
	TEST_ASSERT_EQUAL_INT(-8, func_add(-3, -5));
	TEST_ASSERT_EQUAL_INT(2, func_add(5, -3));
	TEST_ASSERT_EQUAL_INT(-2, func_add(-5, 3));
	TEST_ASSERT_EQUAL_INT(0, func_add(0, 0));
	TEST_ASSERT_EQUAL_INT(5, func_add(5, 0));
	TEST_ASSERT_EQUAL_INT(-5, func_add(0, -5));
	TEST_ASSERT_EQUAL_INT(0, func_add(5, -5));
	TEST_ASSERT_EQUAL_INT(INT32_MAX, func_add(INT32_MAX, 0));
	TEST_ASSERT_EQUAL_INT(INT32_MIN, func_add(INT32_MIN, 0));
	TEST_ASSERT_EQUAL_INT(INT32_MAX, func_add(INT32_MAX - 1, 1));
	TEST_ASSERT_EQUAL_INT(INT32_MIN, func_add(INT32_MIN +1, -1));
}

void test_function_aditionalTests()
{
	TEST_ASSERT_NOT_EQUAL_INT(7, func_add(3, 5));
}

int test_func_add_main()
{
	UNITY_BEGIN();

	//Tests Aufgabe 1
	RUN_TEST(test_function_chatGptTests);
	RUN_TEST(test_function_aditionalTests);

	return UNITY_END();
}
