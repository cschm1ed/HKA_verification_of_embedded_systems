
// File that contain the test code

#include "mytests.h"

// Methode zur Sortierung von drei Zahlen wobei doppelt vorkommende Zahlen durch 0 ersetzt werden
// Aufgabe 3
int* func_sortThreeNumbers(int a, int b, int c)
{
	// Umgebung
	int i, j, temp;
	int printfOutput = True;

	// Array Werte zuweisen
	int* array = malloc(3 *sizeof(int));
	int array_size = 3;

	array[0] = a;
	array[1] = b;
	array[2] = c;

	// Augabe zur Kontrolle
	if (printfOutput)
	{
		printf("Array Ausgabe vor Sortierung: ");
		for (i = 0; i < (array_size); ++i)
		{
			printf("%i; ", array[i]);
		}
		printf("\n");
	}

	// Sortierung der Zahlen und Ersetzung von Dubletten 
	for (i = 0; i < (array_size - 1); ++i)
	{
		for (j = 0; j < array_size - 1 - i; ++j )
		{
			if (array[j] == array[j + 1] && array[i] != 0)
            {
				array[j] = 0;
			}

			if (array[j] < array[j + 1])
			{
				temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
		}
	}

	// Augabe zur Kontrolle
	if (printfOutput)
	{
		printf("Array Ausgabe nach Sortierung:");
		for (i = 0; i < (array_size); ++i)
		{
			printf("%i; ", array[i]);
		}
		printf("\n\n");
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

int Zustaende(int input)
{
	static int zustand = 0;
	
	switch (zustand)
	{
	case 0:
		if (input == 2)
			zustand = 1;
		break;
	case 1:
		zustand = 2;
		break;
	case 2:
		if (input > 20)
			zustand = 0;
			break;
	default:
		zustand = 0;
		break;
	}

	return zustand;
}
