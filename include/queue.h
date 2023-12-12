#ifndef QUEUE_H_   
#define QUEUE_H_
#include "process.h"

typedef struct _queue {
    int size;
    process *start;
    process *end;
} queue;

void initQueue(queue *processQueue);
void enqueue(process *newProcess, queue *processQueue);
process* dequeue(queue *processQueue);

#endif