#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
void *xmalloc(size_t);

void *xmalloc(size_t size)
{
    void *p;
    p = malloc(size);
    if(p == NULL)
    {
        printf("Impossibile allocare %ld byte!\n", size);
        exit(-1);
    }
    return p;
}