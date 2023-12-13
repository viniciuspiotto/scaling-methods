#include "list.h"
#include "process.h"
#include "chance.h"
#include <stdlib.h>



void shortestJobFirst(){
    list processList;  
    initList(&processList);
    process* currentProcess = processList.begin;

    do{
        if(randomChance(0,100) <= 30){
            process *newProcess = createProcess(processList.size);
            insertOnList(newProcess, &processList);
        }

        if(processList.size > 0){
            if(currentProcess != NULL){
                currentProcess->time--;
                if(currentProcess->time == 0){
                    process* removedProcess = removeFromList(&processList, currentProcess->pid);
                    currentProcess = processList.begin;
                }   
            } else {
                currentProcess = processList.begin;
            }
        }
    }while(1);

}