#include "list.h"
#include "process.h"
#include <stdlib.h>

void initList(list* newList) {
    newList->begin = NULL;
    newList->size = 0;
}

void insertOnList(process *newProcess, list *l){
    if(l->begin == NULL || l->begin->time >= newProcess->time){
        newProcess->next = l->begin;
        l->begin = newProcess;
    }else{
        process *aux = l->begin;
        while(aux->next != NULL && aux->next->time < newProcess->time){
            aux = aux->next;
        }
        newProcess->next = aux->next;
        aux->next = newProcess;
    }
    l->size++;
}

process* removeFromList(list* list, int pid) {
    process* aux = list->begin;
    process* prev = NULL;
    while (aux != NULL && aux->pid != pid) {
        prev = aux;
        aux = aux->next;
    }
    if (aux == NULL) {
        return NULL;
    }
    if (prev == NULL) {
        list->begin = aux->next;
    } else {
        prev->next = aux->next;
    }
    list->size--;
    return aux;
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

void initCircular(circularList *list){
    list->start = NULL;
    list->end = NULL;
    list->size = 0;
}

void insertOnCircular(circularList *list, process* newProcess){
    process *aux = list->start;
    if (aux == NULL){
        list->start = newProcess;
        list->end = newProcess;
        newProcess->next = NULL;
    } else { 
        list->end->next = newProcess;
        list->end = newProcess;
        newProcess->next = NULL;
    }
}

process* removeFromCircular(circularList *list){
    process *aux = list->start;
    if (aux != NULL){
        list->start = aux->next;
    }
    list->size--;
    return aux;
}