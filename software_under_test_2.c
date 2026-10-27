
// File that contain the test code

#include "mytests.h"

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

int *func_sortThreeNumbers_state(int a, int b, int c, int *a_smallest, int *b_smallest, int *doublet_exists)
{
	int* array = malloc(3 *sizeof(int));
	int array_size = 3;

	*a_smallest = False;
	*b_smallest = False;
	*doublet_exists = False;

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

	if (array[0] == a)
		*a_smallest = True;

	if (array[0] == b)
		*b_smallest = True;

	if (a == b || a == c || b == c)
		*doublet_exists = True;


	return array;
}
