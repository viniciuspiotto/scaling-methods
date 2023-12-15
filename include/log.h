#ifndef LOG_H_
#define LOG_H_
#include <stdio.h>
#include "process.h"

void logMessage(FILE *file, char *message);
void logMessageFileName(FILE *file, char *fileName);
void logCreateProcess(FILE *file, process* currentProcess, int size);
void logExecuteProcess(FILE *file, process* currentProcess);
void logFinishProcess(FILE *file, process* currentProcess);
void logChangeProcess(FILE *file, process* newProcess, process* oldProcess);

#endif