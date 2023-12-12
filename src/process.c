#include "process.h"
#include "chance.h"
#include <stdlib.h>

process* createProcess(int size) {
    process* newProcess = (process*) malloc(sizeof(process));
    newProcess->pid = size + 1;
    newProcess->time = randomChance(1, 20);
    newProcess->next = NULL;
    return newProcess;
}