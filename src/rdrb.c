#include <stdio.h>
#include <unistd.h>
#include "process.h"
#include "list.h"
#include "rdrb.h"
#include "log.h"
#include "chance.h"

void roundRobin(FILE* file){
    logMessage(file, " [METHOD] Método Round Robin iniciado.\n");
    printf(" [METHOD] Método Round Robin iniciado.\n");
    int clock = 0, quantum = 6; 
    circularList processList;
    initCircular(&processList);

    do {
        if(randomChance(0, 100) <= 30) {
            process *newProcess = createProcess();
            insertOnCircular(&processList, newProcess);
            processList.size++;
            logCreateProcess(file, newProcess, processList.size);
        }

        if(processList.size > 0){
            clock++;
            logExecuteProcess(file, processList.start);
            processList.start->time --;
            if(processList.start->time == 0){
                process* removedProcess = removeFromCircular(&processList);
                clock = 0;
                logFinishProcess(file, removedProcess);
            }
            
            if(clock >= quantum){
                insertOnCircular(&processList, processList.start);
                processList.start = processList.start->next;
                clock = 0;
                logChangeProcess(file, processList.start, processList.end);
            }
        }
        sleep(1);
    } while (1);
}