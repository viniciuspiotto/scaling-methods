#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "interface.h"
#include "fcfs.h"
#include "sjf.h"
#include "rdrb.h"
#include "log.h"

int main(){
    srand(time(0));
    cleanTerminal();
    char fileName[50];
    sprintf(fileName, "relatorio-%d.txt", (int)time(NULL));
    FILE* file = fopen(fileName, "w");
    if(file == NULL){
        printf("Erro ao criar arquivo de relatório.\n");
        exit(1);
    }

    int choice = 0;
    do {
        choice = choiceMethod();
        switch(choice){
            case 1:
                cleanTerminal();
                logMessageFileName(file, fileName);
                firstComeFirstServed(file);
                break;
            case 2:
                cleanTerminal();
                logMessageFileName(file, fileName);
                shortestJobFirst(file);
                break;
            case 3:
                cleanTerminal();
                logMessageFileName(file, fileName);
                roundRobin(file);
                break;
            default:
                cleanTerminal();
                failedChoice();
                break;
        }
    } while(choice > 3 || choice < 1);
    fclose(file);
}