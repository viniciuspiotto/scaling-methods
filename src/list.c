#include "list.h"
#include "process.h"

#include <stdlib.h>

typedef struct _list {
    process *begin;
    int size;
} list;

list* initList() {
    list* newList = (list*) malloc(sizeof(list));
    newList->begin = NULL;
    newList->size = 0;
    return newList;
}

void insertOnList(list *l){
    process* newProcess = createProcess(l->size);
    if(l->begin == NULL){
        l->begin = newProcess;
    }else{
        process *aux = l->begin;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = newProcess;
    }
    l->size++;
}

void removeFromList(list* list) {
    process* aux = list->begin;
    list->begin = aux->next;
    free(aux);
    list->size--;
}

void freeList(list* list) {
    process* aux = list->begin;
    while (aux != NULL) {
        process* next = aux->next;
        free(aux);
        aux = next;
    }
    free(list);
}