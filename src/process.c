#include "process.h"
#include "chance.h"
#include <stdlib.h>

process* createProcess() {
    process* newProcess = (process*) malloc(sizeof(process));
    newProcess->pid = (int)(rand() / 1000);
    newProcess->time = randomChance(1, 20);
    newProcess->next = NULL;
    return newProcess;
}