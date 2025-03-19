#include <stdio.h>
#include <conio.h>
#include <string.h>

// Utils
#include "../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../utils/printColorful/printColorful.h"

// Services
#include "../../../../services/stateManagerService/stateManagerService.h"

int residenceManagerMenu(){
    int option;
    do{
        printColorful("Gerenciando propriedades. Você pode: \n", 3);
        printColorful("1 -> Acessar minhas propriedades.\n", 5);
        printColorful("2 -> Cadastrar propriedade.\n", 5);
        printColorful("3 -> Acessar detalhes de uma propriedade.\n", 5);
        printColorful("4 -> Alterar uma propriedade.\n", 5);
        printColorful("5 -> Remover uma propriedade.\n", 5);
        printColorful("6 -> Voltar.\n", 1);
        
        option = getch();
        option -= '0';
        
        if(option < 1 || option > 6){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 6);
    cleanScreen();
    return option;
}

void residenceManagerMenuChoose(){
    switch (residenceManagerMenu())
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