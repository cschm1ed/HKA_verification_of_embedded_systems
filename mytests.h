#ifndef MYTESTS_H
#define MYTESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// update the direction for unity.h
#include "unity.h"
#include "unity_internals.h"

#define True 1
#define False 0

// Methodenaufrufe
extern int func_add(int a, int b);
extern int* func_sortThreeNumbers(int a, int b, int c);
extern char *my_strcopy(char *src);
int my_divide(int a, int b);
int *func_sortThreeNumbers_state(int a, int b, int c, int *a_smallest, int *b_smallest, int *doublet_exists);
int test_func_add_main();
char *my_srtdup(char *src);
int Zustaende(int input);

#endif
