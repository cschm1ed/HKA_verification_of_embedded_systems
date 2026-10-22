// Unity_Testexample.c : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

// Include only c-libs, no c++ libs
// update the direction for unity.h
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// update the direction for unity.h
#include "unity.h"
#include "unity_internals.h"

// Methodenaufrufe
extern int func_add(int a, int b);
extern int* func_sortThreeNumbers(int a, int b, int c);
extern char *my_strcopy(char *src);

// The function setUp and tearDown are two special function that are executed before each test and after each test.
// There additional execution can be added that need to be added in advance and later to clean up. (e.g. for used dynamic memory)
// If needed add the relevant code. If not: keep the function empty.

void setUp(void)
{
	
}

void tearDown(void)
{
	// cleanup after each test
}

// forward declaration for the main-test function (below main in this file)
int test_func_add_main();


// Main function. No special functionallity. Only add two printf comands to see if the tool finish correct.
int main()
{
	int feedback = 0;
	printf("Start Test\n");
	// The call of the testfunction
	feedback= test_func_add_main();
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

void test_function_testSort()
{
	int *ptr;

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){1, 2, 3}), (ptr = func_sortThreeNumbers(3, 2, 1)), 3);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){1, 2, 0}), (ptr = func_sortThreeNumbers(2, 2, 1)), 3);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){-1, 2, 3}), (ptr = func_sortThreeNumbers(2, -1, 3)), 3);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){INT_MIN, 0, INT_MAX}), (ptr = func_sortThreeNumbers(INT_MAX, 0, INT_MIN)), 3);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){4, 7, 0}), (ptr = func_sortThreeNumbers(4, 4, 7)), 3);
	free(ptr);

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){-1, 2, 3}), (ptr = func_sortThreeNumbers(2, -1, 3)), 3);
	free(ptr);

}

void test_strcpy() {
	char *ptr;

	TEST_ASSERT_EQUAL_STRING("HALLO", (ptr = my_strcopy("HALLO")));
	free(ptr);

	TEST_ASSERT_EQUAL_STRING("TEST123", (ptr = my_strcopy("ABCDEFGHAASDASDASDihfjhsdkfjhskldjfhskdjfhskajldhksjdah")));
	free(ptr);

}

//Beispieltest entfernt
/*

// This test should PASS if the tool works correct
void test_function_normalValueTest4242(void)
{
	TEST_ASSERT_EQUAL_INT(84, func_add(42, 42));
}

// This test should fail if it works correct.
void test_function_normalValueTest4243(void)
{
	TEST_ASSERT_EQUAL_INT(84, func_add(42, 43));
}


void test_function_normalValueTest00(void)
{
	TEST_ASSERT_EQUAL_INT(0, func_add(0, 0));
}

*/


int test_func_add_main()
{
	UNITY_BEGIN();

	//Tests Aufgabe 1
	RUN_TEST(test_function_chatGptTests);
	RUN_TEST(test_function_aditionalTests);

	//Test Aufgabe 3
	RUN_TEST(test_function_testSort);
	RUN_TEST(test_strcpy);
	//Beispieltest entfernt
/*
	RUN_TEST(test_function_normalValueTest4242);
	RUN_TEST(test_function_normalValueTest4243);
	RUN_TEST(test_function_normalValueTest00);
*/

	return UNITY_END();
}




