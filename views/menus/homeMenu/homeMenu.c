#include <stdio.h>
#include <conio.h>

// Utils
#include "../../../utils/cleanScreen/cleanScreen.h"
#include "../../../utils/printColorful/printColorful.h"

// Views

// Controllers

// Services
#include "../../../services/stateManagerService/stateManagerService.h"

int homeMenu(){
    int option;
    do{
        char message[100];
        snprintf(message, sizeof(message), "\n%s, de que forma posso auxiliar? \n", getAuthUserName());
        printColorful(message, 3);
        printColorful("1 -> Opção 1.\n", 5);
        printColorful("2 -> Opção 2.\n", 5);
        printColorful("3 -> Gostaria de sair do sistema.\n", 1);
        
        option = getch();
        option -= '0';
        
        if(option < 1 || option > 3){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 3);
    //cleanScreen();
    return option;
}

int homeMenuChoose(){
    switch (homeMenu())
    {
        case 1:
        printf("Opção 1\n");
        return 1;
        // Opção 1
        break;
        
        case 2:
        printf("Opção 2\n");
        return 1;
        // Opção 2
        break;
        
        case 3:
        printf("Opção 3\n");
        return 0;
        // Opção 3
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        return 1;
        break;
    }
}