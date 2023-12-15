#include <unistd.h>
#include <stdio.h>
#include "rdrb.h"
#include "process.h"
#include "list.h"
#include "chance.h"
#include "log.h"

/**
 * Function that implements the Round Robin method.
 * @param FILE logFile
 */
void roundRobin(FILE* logFile) {
    logMessage(logFile, " [METHOD] Método Round Robin iniciado.\n");
    int clock = 0, quantum = 6; 
    // Initializing the processList
    circularList processList;
    initCircular(&processList);

    do {
        // Checking and creating a new process
        if(randomChance(0, 100) <= 30) {
            process *newProcess = createProcess();
            insertOnCircular(&processList, newProcess);
            processList.size++;
            logCreateProcess(logFile, newProcess, processList.size);
        }
        // Executing the process itself
        if(processList.size > 0) {
            clock++;
            logExecuteProcess(logFile, processList.start);
            processList.start->time --; // Decrementing process time
            if(processList.start->time == 0) { // Checking if the process is over
                process* removedProcess = removeFromCircular(&processList);
                clock = 0;
                logFinishProcess(logFile, removedProcess);
            }
            // If the process time is greater than the quantum,
            //  then swap to the next process.
            if(clock >= quantum) {
                insertOnCircular(&processList, processList.start);
                processList.start = processList.start->next;
                clock = 0;
                logChangeProcess(logFile, processList.start, processList.end);
            }
        }
        sleep(1);
    } while (1);
}