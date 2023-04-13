#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"
#include "item.h"
#include "list.h"

struct c_list
{
    struct node *first;
    int size;
};

struct node
{
    item value;
    struct node *next;
};

int partition(list l, int low, int high);
void quicksort_recursion(list l, int low, int high);

static struct node *getNode(list l, unsigned int pos)
{
    if(pos >= l->size || pos < 0) return NULL;
    struct node *n = l->first;
    int i = 0;
    while(i < pos)
    {
        n = n->next;
        i++;
    }

    return n;
}

static struct node *removeNode(struct node *l, unsigned int pos)
{
    struct node *l1;
    if(pos == 0)
    {
        l1 = l;
        l = l->next;
        remove_item(l1->value);
        free(l1);
    }
    else
    {
        int i= 0;
        struct node *prec = l;
        while(i < pos-1)
        {
            prec = prec->next;
            i++;
        }

        l1 = prec->next;
        prec->next = l1->next;
        remove_item(l1->value);
        free(l1);
    }
    return l;
}

static struct node *insertNode(struct node *l, item value, unsigned int pos)
{
    struct node *new, *prec = l;
    int i = 0;

    new = xmalloc(sizeof(struct node));
    if(!new) return NULL;
    new->value = value;

    if(pos == 0)
    {
        new->next = l;
        return new;
    }
    while(i < pos-1)
    {
        prec = prec->next;
        i++;
    }
    new->next = prec->next;
    prec->next = new;
    return l;
}

int insertList(list l, item value, unsigned int pos)
{
    if(pos < 0 || pos > l->size) return 0;
    struct node *tmp = insertNode(l->first,value,pos);
    if(tmp == NULL) return 0;

    l->first = tmp;
    l->size++;
    return 1;
}

int removeList(list l, unsigned int pos)
{
    if(!l || l->first==NULL || l->size == 0) return 0;
    if(pos < 0 || pos >= l->size) return 0;
    l->first = removeNode(l->first,pos);
    l->size--;
    return 1;
}

list copyList(list l)
{
    list nl;
    item x;
    int i;

    nl = newList();
    for(i = 0; i < l->size; i++)
    {
        if(getItem(l,i,&x))
            insertList(nl,x,i);
        else
        {
            fprintf(stderr,"Error while copying the %d. value!!\n",i+1);
            exit(-1);
        }
    }

    return nl;
}

int searchItem(list l, item value)
{
    struct node *l1 = l->first;
    int trovato = 0;
    
    while(l1 != NULL && trovato == 0)
    {
        if(eq_item(value, l1->value))
        {
            trovato = 1;
        }
        l1 = l1->next;
    }

    return trovato;
}

list reverseList(list l)
{
    struct node *l1 = l->first;
    list n = newList();

    while(l1 != NULL)
    {
        n = consList(n,l1->value);
        l1 = l1->next;
    }

    return n;
}

int getItem(list l, int pos, item *out)
{
    struct node *l1 = l->first;
    int i = 0;
    if(pos < 0 || pos >= l->size) return 0;
    while(i < pos)
    {
        l1 = l1->next;
        i++;
    }
    *out = l1->value;
    return 1;
}

int posItem(list l, item val)
{
    struct node *l1 = l->first;
    int i = 0, trovato = 0;

    while(l1 != NULL && !trovato)
    {
        if(eq_item(val,l1->value))
        {
            trovato = 1;
        }
        l1 = l1->next;
        i++;
    }
    if(trovato)
        return i-1;
    return -1;
}

int sizeList(list l)
{
    if(!emptyList(l))
        return l->size;
    return 0;
}

item getFirst(list l)
{
    if(!emptyList(l))
        return l->first->value;
    return NULL;
}

list consList(list l, item value)
{
    struct node *n;
    n = xmalloc(sizeof(struct node));
    n->value = value;
    n->next = l->first;
    l->first = n;
    l->size++;
    return l;
}

int emptyList(list l)
{
    return l->first == NULL;
}

list newList()
{
    struct c_list *l;
    l = xmalloc(sizeof(struct c_list));
    l->first = NULL;
    l->size = 0;
    return l;
}

void sortList(list l)
{
    srand(time(NULL));
    quicksort_recursion(l,0,l->size - 1);
}

void quicksort_recursion(list l, int low, int high)
{
    if(low < high)
    {
        int pivot_index = partition(l, low, high);
        quicksort_recursion(l,low,pivot_index-1);
        quicksort_recursion(l,pivot_index+1,high);
    }
}

int partition(list l, int low, int high)
{
    int pivot_index = low + (rand() & (high - low));
    int i = low;
    struct node *iNode, *jNode, *pNode = getNode(l,pivot_index), *hNode = getNode(l,high);

    if(pivot_index != high)
    {
        swap_item(&(pNode->value), &(hNode->value));
        pNode = hNode;
    }

    pivot_index = high;
    for(int j = low; j < pivot_index; j++)
    {
        iNode = getNode(l,i);
        jNode = getNode(l,j);
        if(compare_items(jNode->value, pNode->value) <= 0)
        {
            swap_item(&(iNode->value),&(jNode->value));
            i++;
        }
    }
    iNode = getNode(l,i);
    swap_item(&(iNode->value),&(pNode->value));
    return i;
}