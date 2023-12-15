#include <stdlib.h>
#include "queue.h"
#include "process.h"

/**
 * Function that initializes the process queue.
 * @param queue processQueue
 */
void initQueue(queue *processQueue) {
    processQueue->size = 0;
    processQueue->start = NULL;
    processQueue->end = NULL;
}

/**
 * Function that inserts a new process on the process queue.
 * @param   process   newProcess
 * @param   queue     processQueue
 */
void enqueue(process *newProcess, queue *processQueue) {
    if(processQueue->end != NULL) {
        processQueue->end->next = newProcess;
    } else {
        processQueue->start = newProcess;
    }
    processQueue->end = newProcess;
    processQueue->size++;
}

/**
 * Function that removes a process from the process queue.
 * @param queue processQueue
 *
 * @return process
 */
process* dequeue(queue *processQueue) {
    process *aux = NULL;
    if(processQueue->start != NULL) {
        aux = processQueue->start;
        processQueue->start = processQueue->start->next;
        if(processQueue->start == NULL) {
            processQueue->end = NULL;
        }
    }
    processQueue->size--;
    return aux;
}