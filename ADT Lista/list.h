#include "item.h"

typedef struct c_list* list;

void sortList(list);
list newList();
int emptyList(list);
list consList(list,item);
item getFirst(list);
int sizeList(list);
int posItem(list, item);
int getItem(list, int, item*);
list reverseList(list);
int searchItem(list, item);
list copyList(list);
int removeList(list, unsigned int);
int insertList(list, item, unsigned int);