#ifndef LIST_H_  
#define LIST_H_
#include "process.h"

typedef struct _list{
    process *begin;
    int size;
} list;

typedef struct _circularList{
    process *start;
    process *end;
    int size;
} circularList;

void initList(list* newList);
void insertOnList(process *newProcess, list *l);
process* removeFromList(list* list, int pid);
void freeList(list *l);

void initCircular(circularList *list);
void insertOnCircular(circularList *list, process* newprocess);
process* removeFromCircular(circularList *list);

#endif