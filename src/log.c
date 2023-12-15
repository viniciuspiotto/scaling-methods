#include "log.h"
#include "process.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void logMessage(FILE *file, char *message) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char timestamp[20];
    strftime(timestamp, 20, "%d-%m-%Y %H:%M:%S", tm_info);
    fprintf(file, "[%s]%s", timestamp, message);
}

void logMessageFileName(FILE *file, char *fileName) {
    char logMessageBuffer[100];
    snprintf(logMessageBuffer, sizeof(logMessageBuffer), " [INFO] Informações salvas no arquivo %s\n", fileName);
    printf("%s", logMessageBuffer);
    logMessage(file, logMessageBuffer);
}

void logCreateProcess(FILE *file, process* currentProcess, int size) {
    char logMessageBuffer[100];
    snprintf(logMessageBuffer, sizeof(logMessageBuffer), " [CREATE] %-5sPID: %-7d | time: %-2d | (%d restantes)\n", "", currentProcess->pid, currentProcess->time, size);
    printf("%s", logMessageBuffer);
    logMessage(file, logMessageBuffer);
}

void logExecuteProcess(FILE *file, process* currentProcess) {
    char logMessageBuffer[100];
    snprintf(logMessageBuffer, sizeof(logMessageBuffer), " [EXEC] %-7sPID: %-7d | time: %-2d\n", "", currentProcess->pid, currentProcess->time);
    printf("%s", logMessageBuffer);
    logMessage(file, logMessageBuffer);
}

void logFinishProcess(FILE *file, process* currentProcess) {
    char logMessageBuffer[100];
    snprintf(logMessageBuffer, sizeof(logMessageBuffer), " [FINISH] %-10sPID: %-7d\n", "", currentProcess->pid);
    printf("%s", logMessageBuffer);
    logMessage(file, logMessageBuffer);
}

void logChangeProcess(FILE *file, process* newProcess, process* oldProcess) {
    char logMessageBuffer[100];
    snprintf(logMessageBuffer, sizeof(logMessageBuffer), " [CHANGE] %-5sPID: %-7d | time: %-2d -> PID: %-7d | time: %-2d\n", "", oldProcess->pid, oldProcess->time, newProcess->pid, newProcess->time);
    printf("%s", logMessageBuffer);
    logMessage(file, logMessageBuffer);
}