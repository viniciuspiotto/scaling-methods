#ifndef PROC_H_   
#define PROC_H_

typedef struct _process {
    int pid;
    int time;
    struct _process *next;
} process;

process* createProcess();

#endif