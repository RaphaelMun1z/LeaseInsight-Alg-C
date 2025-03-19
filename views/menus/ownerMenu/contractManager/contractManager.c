#include <stdio.h>
#include <conio.h>
#include <string.h>

// Utils
#include "../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../utils/printColorful/printColorful.h"

// Services
#include "../../../../services/stateManagerService/stateManagerService.h"

int contractManagerMenu(){
    int option;
    do{
        printColorful("Gerenciando contratos. Você pode: \n", 3);
        printColorful("1 -> Acessar meus contratos.\n", 5);
        printColorful("2 -> Acessar detalhes de um contrato.\n", 5);
        printColorful("3 -> Alterar um contrato.\n", 5);
        printColorful("4 -> Remover um contrato.\n", 5);
        printColorful("5 -> Voltar.\n", 1);
        
        option = getch();
        option -= '0';
        
        if(option < 1 || option > 5){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 5);
    cleanScreen();
    return option;
}

void contractManagerMenuChoose(){
    switch (contractManagerMenu())
    {
        case 1:
        printf("Opção 1\n");
        // Opção 1
        break;
        
        case 2:
        printf("Opção 2\n");
        // Opção 2
        break;
        
        case 3:
        printf("Opção 3\n");
        // Opção 3
        break;
        
        case 4:
        printf("Opção 4\n");
        // Opção 4
        break;
        
        case 5:
        printf("Opção 5\n");
        // Opção 5
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}