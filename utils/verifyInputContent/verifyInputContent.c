#include <stdio.h>
#include <string.h>

#define TAM_BUFFER 100

int returnValidInt()
{
    char buffer[TAM_BUFFER];
    int opcao = 0;
    
    while (1){
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &opcao) != 1){
            printf("Opcao invalida. Tente novamente.\n");
        } else{
            return opcao;
        }
    }
}