#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

void stampa(list lista)
{
    item x;
    for(int i = 0; i < sizeList(lista); i++)
    {
        getItem(lista,i,&x);
        printf("%d:", i+1);
        output_item(x);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    list l = newList();
    item value;
    printf("Inserisci l'item: ");
    value = input_item();
    printf("item in top: ");
    output_item(getFirst(l));
    printf("\n");
    consList(l,value);
    printf("item in top: ");
    output_item(getFirst(l));
    printf("\n");
    printf("Size: %d", sizeList(l));
    printf("Inputta l'item: ");
    value = input_item();
    if(insertList(l,value,3))
        printf("Inserito nella posizione 3\n");
    else
        printf("Non inserito nella posizione 3\n");

    if(insertList(l,value,1))
        printf("Inserito nella posizione 1\n");
    else
        printf("Non inserito nella posizione 1\n");
    /*
    if(removeList(l,5))
        printf("Eliminato nella posizione 5\n");
    else
        printf("Non eliminato nella posizione 5\n");

    if(removeList(l,0))
        printf("Eliminato nella posizione 0\n");
    else
        printf("Non eliminato nella posizione 0\n");*/
    printf("Size: %d", sizeList(l));
    stampa(l);
    return 0;
}