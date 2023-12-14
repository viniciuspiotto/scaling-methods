#include "process.h"
#include "queue.h"
#include "chance.h"

void firstComeFirstServed() {
    queue processQueue;
    initQueue(&processQueue);
    do {
        if(randomChance(0, 100) <= 30) {
            process *newProcess = createProcess();
            enqueue(newProcess, &processQueue);
        }
        if(processQueue.size > 0) {
            processQueue.start->time--;
            if(processQueue.start->time == 0) {
                process* removedProcess = dequeue(&processQueue);
            }
        }
    } while (1);
}