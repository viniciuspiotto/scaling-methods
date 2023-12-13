#include <stdio.h>
#include <stdlib.h>

void failedChoice(){
    printf("*--------------------------------------*\n");
    printf("|            Opção inválida            |\n");
    printf("*--------------------------------------*\n\n\n");
}

int choiceMethod(){
    int choice;
    printf("Escolha um método: \n\n");
    printf("1. First Come First Serve\n");
    printf("2. Shortest Job First\n");
    printf("3. Round Robin\n");
    printf("\nDigite sua escolha: ");
    scanf("%d", &choice);
    return choice;
}

void cleanTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}