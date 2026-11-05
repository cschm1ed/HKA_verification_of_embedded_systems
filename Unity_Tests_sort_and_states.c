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

	TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){3, 0, -1}), (ptr = func_sortThreeNumbers(3, 3, 3)), 3);
	free(ptr);
}

void test_function_testSort_and_State() {
	int *ptr;
	int a_smallest, b_smallest, doublet_exists;
	int expectedA[5] = {1, 1, 1, 1, 1}, 
		expectedB[5] = {2, 2, 2, 2, 2}, 
		expectedC[5] = {3, 0, 3, 0, 0};
	int expectedASmallest[5] = {False, False, True, False, False}, 
		expectedBSmallest[5] = {False, False, False, False, True}, 
		expectedDoubletExists[5] = {False, True, False, True, True};
	int inputA[5] = {3, 2, 1, 2, 2}, 
		inputB[5] = {2, 2, 3, 2, 2}, 
		inputC[5] = {1, 1, 2, 1, 1};

	/*
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
	*/

	for (size_t i = 0; i < 5; i++)
	{
		TEST_ASSERT_EQUAL_INT_ARRAY(((int[]){expectedA[i], expectedB[i], expectedC[i]}), (ptr = func_sortThreeNumbers_state(inputA[i], inputB[i], inputC[i], &a_smallest, &b_smallest, &doublet_exists)), 3);
		TEST_ASSERT_EQUAL_INT(expectedASmallest[i], a_smallest);
		TEST_ASSERT_EQUAL_INT(expectedBSmallest[i], b_smallest);
		TEST_ASSERT_EQUAL_INT(expectedDoubletExists[i], doublet_exists);
		free(ptr);
	}
	
}

/*
  0 ------> 1 --------> 2 ----------|
  |	  i=2		      		i>20    |
  -----------------------------------
*/
void test_function_Zustaende()
{
	int zustandSimulation = 0;

	printf("Dokumentation der Durchläufe zur Nachverfolgung: ");

	for (size_t i = 0; i < 25; i++)
	{
		if (zustandSimulation == 0){
			if (i == 2)
			{
				printf("1; ");
				TEST_ASSERT_EQUAL_INT(1, (zustandSimulation = Zustaende(i)));
			}
			else
			{
				printf("2; ");
				TEST_ASSERT_EQUAL_INT(0, (zustandSimulation = Zustaende(i)));
			}
		}
		else if (zustandSimulation == 1)
		{
			printf("3; ");
			TEST_ASSERT_EQUAL_INT(2, (zustandSimulation = Zustaende(i)));
		}
		else if (zustandSimulation == 2)
		{
			if (i > 20)
			{
				printf("4; ");
				TEST_ASSERT_EQUAL_INT(0, (zustandSimulation = Zustaende(i)));
			}
			else
			{
				printf("5; ");
				TEST_ASSERT_EQUAL_INT(2, (zustandSimulation = Zustaende(i)));
			}
		}
	}

	printf("\n");
}

void test_function_ZustaendeGezielt()
{
	int zustandSimulation = 0;

	TEST_ASSERT_EQUAL_INT(0, (Zustaende(0)));

	for (int i = INT32_MIN; i <= INT32_MAX; i++) {
		if (i != 2)
			TEST_ASSERT_EQUAL_INT(0, (zustandSimulation = Zustaende(i)));
	}
	TEST_ASSERT_EQUAL_INT(1, (zustandSimulation = Zustaende(2)));
	printf("Zustand 0 done\n");
	for (int i = INT32_MIN; i <= INT32_MAX; i++) {
		set_to_1();
		TEST_ASSERT_EQUAL_INT(2, (zustandSimulation = Zustaende(i)));
	}
	printf("Zustand 1 done\n");
	for (int i = INT32_MIN; i <= INT32_MAX; i++) {
		set_to_2();
		if (i <= 20)
			TEST_ASSERT_EQUAL_INT(2, (zustandSimulation = Zustaende(i)));
		else
			TEST_ASSERT_EQUAL_INT(0, (zustandSimulation = Zustaende(i)));
	}
}

void set_to_1() {
	int zustandSimulation = Zustaende(2);

	if (zustandSimulation == 0) {
		zustandSimulation = Zustaende(2);
	} else if (zustandSimulation == 1) {
	} else {
		zustandSimulation = Zustaende(21);
	}

	if (zustandSimulation != 1)
	{
		printf("Zstand fehlgeschlagen");
	}
	return ;
}

void set_to_2() {
	int zustandSimulation = Zustaende(2);

	if (zustandSimulation == 0) {
		zustandSimulation = Zustaende(2);
		zustandSimulation = Zustaende(42);
	} 
	else if (zustandSimulation == 1) 
	{
		zustandSimulation = Zustaende(42);
	} 
	else 
	{
		;
	}

	if (zustandSimulation != 2)
		printf("Error: Zustand set to 2 fehlgeschlagen\n");
	return ;

}

int test_func_add_main()
{
	UNITY_BEGIN();
	//RUN_TEST(test_function_testSort);
	//RUN_TEST(test_function_testSort_and_State);
	//RUN_TEST(test_function_Zustaende);
	RUN_TEST(test_function_ZustaendeGezielt);
	return UNITY_END();
}
