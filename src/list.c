#include "list.h"
#include "process.h"
#include <stdlib.h>

/**
 * Function that initializes the process list.
 * @param list processList
 */
void initList(list* processList) {
    processList->begin = NULL;
    processList->size = 0;
}

/**
 * Function that inserts a new process on the process list.
 * @param   process   newProcess
 * @param   list      processList
 */
void insertOnList(process *newProcess, list *processList) {
    if(processList->begin == NULL || processList->begin->time >= newProcess->time) {
        newProcess->next = processList->begin;
        processList->begin = newProcess;
    } else {
        process *aux = processList->begin;
        while(aux->next != NULL && aux->next->time < newProcess->time) {
            aux = aux->next;
        }
        newProcess->next = aux->next;
        aux->next = newProcess;
    }
    processList->size++;
}

/**
 * Function that removes a process from the process list by the PID.
 * @param   list    processList
 * @param   int     pid
 *
 * @return process
 */
process* removeFromList(list* processList, int pid) {
    process* aux = processList->begin;
    process* prev = NULL;
    while (aux != NULL && aux->pid != pid) {
        prev = aux;
        aux = aux->next;
    }
    if (aux == NULL) {
        return NULL;
    }
    if (prev == NULL) {
        processList->begin = aux->next;
    } else {
        prev->next = aux->next;
    }
    processList->size--;
    return aux;
}

/**
 * Function that remove all the process and free them.
 * @param list processList
 */
void freeList(list* processList) {
    process* aux = processList->begin;
    while (aux != NULL) {
        process* next = aux->next;
        free(aux);
        aux = next;
    }
    free(processList);
}

/**
 * Function that initializes the circular process list.
 * @param circularList processList
 */
void initCircular(circularList *processList) {
    processList->start = NULL;
    processList->end = NULL;
    processList->size = 0;
}

/**
 * Function that inserts a new process on the circular process list.
 * @param   circularList    processList
 * @param   process         newProcess
 */
void insertOnCircular(circularList *processList, process* newProcess) {
    process *aux = processList->start;
    if (aux == NULL) {
        processList->start = newProcess;
        processList->end = newProcess;
    } else { 
        processList->end->next = newProcess;
        processList->end = newProcess;
    }
}

/**
 * Function that removes a process from the circular process list.
 * @param circularList processList
 *
 * @return process
 */
process* removeFromCircular(circularList *processList) {
    process *aux = processList->start;
    if (aux != NULL) {
        processList->start = aux->next;
    }
    processList->size--;
    return aux;
}