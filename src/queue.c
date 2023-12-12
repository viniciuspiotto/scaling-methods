#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "process.h"

void initQueue(queue *processQueue) {
    processQueue->size = 0;
    processQueue->start = NULL;
    processQueue->end = NULL;
}

void enqueue(process *newProcess, queue *processQueue) {
    if(processQueue->end != NULL) {
        processQueue->end->next = newProcess;
    } else {
        processQueue->start = newProcess;
    }
    processQueue->end = newProcess;
    processQueue->size++;
}

process* dequeue(queue *processQueue) {
    process *aux = processQueue->start;
    processQueue->start = aux->next;
    processQueue->size--;
    return aux;
}