#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "utilities.h"

void swap_item(item *it1, item *it2)
{
    item x;
    x = *it1;
    *it1 = *it2;
    *it2 = x;
}

int compare_items(item x, item y)
{
    char *a, *b;
    a = x;
    b = y;
    if(*a > *b)   return 1;
    if(*a < *b)   return -1;
    return 0;
}

void *get_item_value(item x)
{
    int *a = x;
    return a;
}

int eq_item(item x, item y)
{
    char *a, *b;
    a = x;
    b = y;
    return *a == *b;
}

item input_item()
{
    char *x;
    x = xmalloc(sizeof(char));
    scanf("%c", x);
    return x;
}

void output_item(item x)
{
    char *a = x;
    if(x != NULL)
        printf("%c",*a);
    else
        printf("NULL");
}

void remove_item(item x)
{
    free(x);
}