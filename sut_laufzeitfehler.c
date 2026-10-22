
#include <stdlib.h>

char *my_strcopy(char *src) {
    int i = 0;
    char *copy = malloc(sizeof(char) * 10);

    while (*src) {
        copy[i] = *src;
        i ++;
        src++;
    }
    return copy;
}

