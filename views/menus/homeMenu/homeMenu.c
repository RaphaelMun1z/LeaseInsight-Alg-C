#include <stdio.h>
#include <conio.h>
#include <string.h>

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
        char message[100], name[100];
        (getAuthUserName() != NULL) ? strcpy(name, getAuthUserName()) : strcpy(name, "Não foi possível carregar.");
        snprintf(message, sizeof(message), "\n%s, de que forma posso auxiliar? \n", name);
        printColorful(message, 3);
        printColorful("1 -> Gostaria de acessar meus contratos.\n", 5); // Consulta de Contrato
        printColorful("2 -> Gostaria de cancelar um contrato.\n", 5); // Remoção de Contrato
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

void homeMenuChoose(){
    switch (homeMenu())
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
        removeAuthUser();
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}