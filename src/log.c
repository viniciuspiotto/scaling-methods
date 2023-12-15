#include <stdio.h>
#include <time.h>
#include "log.h"
#include "process.h"

/**
 * Function that formats and prints all the specific message logs to 
 *  the stdout and to the log file.
 * @param FILE logFile
 * @param char message
 */
void logMessage(FILE *logFile, char *message) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char timestamp[20];
    strftime(timestamp, 20, "%d-%m-%Y %H:%M:%S", tm_info);
    fprintf(logFile, "[%s]%s", timestamp, message);
    printf("%s", message);
}

/**
 * Function that formats the message telling the user the log filename.
 * @param FILE logFile
 * @param char fileName
 */
void logMessageFileName(FILE *logFile, char *fileName) {
    char logMessageBuffer[100];
    snprintf(logMessageBuffer, sizeof(logMessageBuffer), " [INFO] Informações salvas no arquivo \"%s\"\n", fileName);
    logMessage(logFile, logMessageBuffer);
}

/**
 * Function that formats the message telling the user when a 
 *  process has been created.
 * @param   FILE        logFile
 * @param   process     currentProcess
 * @param   int         numRemainingProcs
 */
void logCreateProcess(FILE *logFile, process* currentProcess, int numRemainingProcs) {
    char logMessageBuffer[100];
    snprintf(logMessageBuffer, sizeof(logMessageBuffer), " [CREATE] %-5sPID: %-7d | time: %-2d | (%d restantes)\n", "", currentProcess->pid, currentProcess->time, numRemainingProcs);
    logMessage(logFile, logMessageBuffer);
}

/**
 * Function that formats the message telling the user that
 *  a process is being executed.
 * @param   FILE        logFile
 * @param   process     currentProcess
 */
void logExecuteProcess(FILE *logFile, process* currentProcess) {
    char logMessageBuffer[100];
    snprintf(logMessageBuffer, sizeof(logMessageBuffer), " [EXEC] %-7sPID: %-7d | time: %-2d\n", "", currentProcess->pid, currentProcess->time);
    logMessage(logFile, logMessageBuffer);
}

/**
 * Function that formats the message telling the user that
 *  a process has been finished.
 * @param   FILE        logFile
 * @param   process     currentProcess
 */
void logFinishProcess(FILE *logFile, process* currentProcess) {
    char logMessageBuffer[100];
    snprintf(logMessageBuffer, sizeof(logMessageBuffer), " [FINISH] %-10sPID: %-7d\n", "", currentProcess->pid);
    logMessage(logFile, logMessageBuffer);
}

/**
 * Function that formats the message telling the user that
 *  occurred a process swap - related to Round Robin method.
 * @param   FILE        logFile
 * @param   process     newProcess
 * @param   process     oldProcess
 */
void logChangeProcess(FILE *logFile, process* newProcess, process* oldProcess) {
    char logMessageBuffer[100];
    snprintf(logMessageBuffer, sizeof(logMessageBuffer), " [CHANGE] %-5sPID: %-7d | time: %-2d ->  PID: %-7d | time: %-2d\n", "", oldProcess->pid, oldProcess->time, newProcess->pid, newProcess->time);
    logMessage(logFile, logMessageBuffer);
}