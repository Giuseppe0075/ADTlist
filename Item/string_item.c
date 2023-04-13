#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "utilities.h"

#define MAXLENGTH 51

void swap_item(item *it1, item *it2)
{
    item *x;
    x = it1;
    it1 = it2;
    it2 = x;
}

int compare_items(item x, item y)
{
    char *a, *b;
    a = x;
    b = y;
    return strcmp(a,b);
}

void *get_item_value(item x)
{
    char *a = x;
    return a;
}

int eq_item(item x, item y)
{
    char *a, *b;
    a = x;
    b = y;
    if(strcmp(a,b) == 1)
        return 1;
    return 0;
}

item input_item()
{
    char *x;
    x = xmalloc(sizeof(char) * MAXLENGTH);
    fgets(x,MAXLENGTH,stdin);
    x[strcspn(x,"\r\n")] = 0;
    return x;
}

void output_item(item x)
{
    char *a = x;
    if(x != NULL)
        printf("%s",a);
    else
        printf("NULL");
}

void remove_item(item x)
{
    free(x);
}