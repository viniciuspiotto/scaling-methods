#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "list.h"
#include "rdrb.h"
#include "chance.h"

void roundRobin(){
    int clock = 0, quantum = 6; 
    circularList processList;
    initCircular(&processList);

    while (1){
        if(randomChance(0, 100) <= 30) {
            process *newProcess = createProcess();
            insertOnCircular(&processList, newProcess);
            processList.size++;
        }

        if(processList.size > 0){
            clock++;
            processList.start->time --;
            if(processList.start->time == 0){
                process* removedProcess = removeFromCircular(&processList);
                clock = 0;
            }
            
            if(clock >= quantum){
                insertOnCircular(&processList, processList.start);
                processList.start = processList.start->next;
                clock = 0;
            }
        }
    }
}