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
            process *newProcess = createProcess(processList.size);
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











/**
}
rdrb{

while (1){

geraProcesso;
  //caso gere um pocesso, 
  insere na lita

 contador ++

 olha o 1° id da lista, e tira 1 do tempo;
   // caso o tempo chegue a 0
    kill 
    contador = 0

 se contador > 5
    proximo processo
    contador = 0
}
*/



// 5 1 2 4













