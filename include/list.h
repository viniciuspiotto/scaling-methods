#ifndef LIST_H_  
#define LIST_H_

#include "process.h"

typedef struct _list{
    process *begin;
    int size;
} list;

void initList(list* newList);
void insertOnList(process *newProcess, list *l);
process* removeFromList(list* list, int pid);
void freeList(list *l);

#endif // LIST_H_