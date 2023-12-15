#include <unistd.h>
#include <stdio.h>
#include "fcfs.h"
#include "process.h"
#include "queue.h"
#include "chance.h"
#include "log.h"

/**
 * Function that implements the First Come First Served method.
 * @param FILE logFile
 */
void firstComeFirstServed(FILE* logFile) {
    logMessage(logFile, " [METHOD] Método First Come First Served iniciado.\n");
    // Initializing the processQueue
    queue processQueue;
    initQueue(&processQueue);

    do {
        // Checking and creating a new process
        if(randomChance(0, 100) <= 30) {
            process *newProcess = createProcess();
            enqueue(newProcess, &processQueue);
            logCreateProcess(logFile, newProcess, processQueue.size);
        }
        // Executing the process itself
        if(processQueue.size > 0) {
            logExecuteProcess(logFile, processQueue.start);
            processQueue.start->time--; // Decrementing process time
            // Checking if the process is over
            if(processQueue.start->time == 0) {
                process* removedProcess = dequeue(&processQueue);
                logFinishProcess(logFile, removedProcess);
            }
        }
        sleep(1);
    } while (1);
}