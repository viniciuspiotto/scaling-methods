#include <unistd.h>
#include <stdio.h>
#include "sjf.h"
#include "process.h"
#include "list.h"
#include "chance.h"
#include "log.h"

/**
 * Function that implements the Shortest Job First method.
 * @param FILE logFile
 */
void shortestJobFirst(FILE *logFile) {
    logMessage(logFile, " [METHOD] Método Shortest Job First iniciado.\n");
    list processList;
    // Initializing the processList
    initList(&processList);
    process *currentProcess = processList.begin; // Saving the currentProcess
    
    do {
        // Checking and creating a new process
        if (randomChance(0, 100) <= 30) {
            process *newProcess = createProcess(processList.size);
            insertOnList(newProcess, &processList);
            logCreateProcess(logFile, newProcess, processList.size);
        }
        // Executing the process itself
        if (processList.size > 0) {
            // Checking if the currentProcess isn't NULL
            if (currentProcess != NULL) {
                logExecuteProcess(logFile, currentProcess);
                currentProcess->time--; // Decrementing process time
                if (currentProcess->time == 0) { // Checking if the process is over
                    process *removedProcess = removeFromList(&processList, currentProcess->pid);
                    logFinishProcess(logFile, removedProcess);
                    currentProcess = processList.begin;
                }
            } else { // Otherwise, grab the first of the process list
                currentProcess = processList.begin;
            }
        }
        sleep(1);
    } while (1);
}