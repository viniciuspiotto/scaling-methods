#include "process.h"
#include "queue.h"
#include "chance.h"
#include "log.h"

void firstComeFirstServed(FILE* file) {
    logMessage(file, " [METHOD] Método First Come First Served iniciado.\n");
    printf(" [METHOD] Método First Come First Served iniciado.\n");
    queue processQueue;
    initQueue(&processQueue);

    do {
        if(randomChance(0, 100) <= 30) {
            process *newProcess = createProcess();
            enqueue(newProcess, &processQueue);
            logCreateProcess(file, newProcess, processQueue.size);
        }
        if(processQueue.size > 0) {
            logExecuteProcess(file, processQueue.start);
            processQueue.start->time--;
            if(processQueue.start->time == 0) {
                process* removedProcess = dequeue(&processQueue);
                logFinishProcess(file, removedProcess);
            }
        }
        sleep(1);
    } while (1);
}