#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include "process.h"

void logMessage(FILE *file, char *message);
void logCreateProcess(FILE *file, process* currentProcess, int size);
void logExecuteProcess(FILE *file, process* currentProcess);
void logFinishProcess(FILE *file, process* currentProcess);

#endif