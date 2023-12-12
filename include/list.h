#ifndef LIST_H_  
#define LIST_H_

typedef struct _list list;

list* initList();
void insertOnList(list *l);
void removeFromList(list *l);
void freeList(list *l);

#endif // LIST_H_