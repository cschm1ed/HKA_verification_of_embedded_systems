

#include "mytests.h"

// Methode zur Division von zwei Zahlen
int my_divide(int a, int b) 
{
    return a / b;
}

char *my_srtdup(char *src)
{
	char *out = malloc(sizeof(char) * 10);
	int i = 0;

	while (src[i]) {
		out[i] = src[i];
		i ++;
	}
	return out;
}
