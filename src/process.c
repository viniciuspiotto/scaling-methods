#include "process.h"
#include "chance.h"
#include <stdlib.h>

/**
 * Function that creates a new process.
 *
 * @return process
 */
process* createProcess() {
    process* newProcess = (process*) malloc(sizeof(process));
    newProcess->pid = (int)(rand() / 1000); // Random generating the PID
    newProcess->time = randomChance(1, 20); // Random generating the time
    newProcess->next = NULL;
    return newProcess;
}