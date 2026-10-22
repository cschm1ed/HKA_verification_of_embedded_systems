#include <stdlib.h>
// File that contain the test code

int func_add(int a, int b)
{
	int result = a + b;
	return result;

}

int* func_sortThreeNumbers(int a, int b, int c)
{
	int* array = malloc(3 *sizeof(int));
	int array_size = 3;

	//Werte zuweisen
	array[0] = a;
	array[1] = b;
	array[2] = c;
	

	int i, j, temp;
    for (i = 0; i < (array_size - 1); ++i)
    {
        for (j = 0; j < array_size - 1 - i; ++j )
        {
            if (array[j] > array[j+1])
            {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }

	if (array[0] == array[1])
	{
		int tmp = array[2];
		array[2] = 0;
		array[1] = tmp;
	}

	if (array[1] == array[2])
	{
		array[2] = 0;
	}

	return array;
}