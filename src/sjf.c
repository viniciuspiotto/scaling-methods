#include <unistd.h>
#include "list.h"
#include "process.h"
#include "chance.h"
#include "sjf.h"
#include "log.h"

void shortestJobFirst(FILE *file) {
    logMessage(file, " [METHOD] Método Shortest Job First iniciado.\n");
    printf(" [METHOD] Método Shortest Job First iniciado.\n");
    list processList;
    initList(&processList);
    process *currentProcess = processList.begin;
    
    do {
        if (randomChance(0, 100) <= 30) {
            process *newProcess = createProcess(processList.size);
            insertOnList(newProcess, &processList);
            logCreateProcess(file, newProcess, processList.size);
        }

        if (processList.size > 0) {
            if (currentProcess != NULL) {
                logExecuteProcess(file, currentProcess);
                currentProcess->time--;
                if (currentProcess->time == 0) {
                    process *removedProcess = removeFromList(&processList, currentProcess->pid);
                    logFinishProcess(file, removedProcess);
                    currentProcess = processList.begin;
                }
            } else {
                currentProcess = processList.begin;
            }
        }
        sleep(1);
    } while (1);
}