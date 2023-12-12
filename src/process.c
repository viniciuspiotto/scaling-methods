#include "process.h"
#include "chance.c"

typedef struct _process {
    int pid;
    int time;
    struct _process *next;
} process;

process* create_process(int size) {
    process* new_process = (process*) malloc(sizeof(process));
    new_process->pid = size + 1;
    new_process->time = random_chance(1, 20);
    new_process->next = NULL;
    return new_process;
}