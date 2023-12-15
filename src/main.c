#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fcfs.h"
#include "sjf.h"
#include "rdrb.h"
#include "log.h"
#include "interface.h"

/**
 * Main function that brings together all main files and functions
 */
int main() {
    srand(time(0)); // Setting the seed for the random numbers
    cleanTerminal();
    char fileName[50];
    // Creating the log filename
    sprintf(fileName, "relatorio-%d.txt", (int)time(NULL));
    // Opening the log file
    FILE* logFile = fopen(fileName, "w");
    if(logFile == NULL){
        printf("Erro ao criar arquivo de relatório.\n");
        exit(1);
    }

    int choice = 0;
    do {
        choice = choiceMethod();
        switch(choice) {
            case 1: // First Come First Served
                cleanTerminal();
                logMessageFileName(logFile, fileName);
                firstComeFirstServed(logFile);
                break;
            case 2: // Shortest Job First
                cleanTerminal();
                logMessageFileName(logFile, fileName);
                shortestJobFirst(logFile);
                break;
            case 3: // Round Robin
                cleanTerminal();
                logMessageFileName(logFile, fileName);
                roundRobin(logFile);
                break;
            default:
                cleanTerminal();
                failedChoice();
                break;
        }
    } while(choice > 3 || choice < 1);
    fclose(logFile);
}