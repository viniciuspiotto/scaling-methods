#include <stdio.h>
#include <stdlib.h>

/**
 * Function that prints error after an invalid option has been choosen.
 */
void failedChoice() {
    printf("*--------------------------------------*\n");
    printf("|            Opção inválida            |\n");
    printf("*--------------------------------------*\n\n\n");
}

/**
 * Function that collects the method desired by the user.
 *
 * @return int
 */
int choiceMethod() {
    int choice;
    printf("Escolha um método: \n\n");
    printf("1. First Come First Serve\n");
    printf("2. Shortest Job First\n");
    printf("3. Round Robin\n");
    printf("\nDigite sua escolha: ");
    scanf("%d", &choice);
    return choice;
}

/**
 * Function that clears the terminal.
 *  It uses the _WIN32 macro to determine the OS type.
 */
void cleanTerminal() {
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // *nix
    #endif
}