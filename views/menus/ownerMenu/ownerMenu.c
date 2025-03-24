#include <stdio.h>
#include <string.h>

// Utils
#include "../../../utils/cleanScreen/cleanScreen.h"
#include "../../../utils/printColorful/printColorful.h"

// Services
#include "../../../services/stateManagerService/stateManagerService.h"

// Views
#include "./residenceManagerMenu/residenceManagerMenu.h"
#include "./contractManagerMenu/contractManagerMenu.h"

int ownerMenu(){
    int option;
    do{
        char message[100], name[100];
        (getAuthUserName() != NULL) ? strcpy(name, getAuthUserName()) : strcpy(name, "Não foi possível carregar.");
        snprintf(message, sizeof(message), "\n%s, de que forma posso auxiliar? \n", name);
        printColorful(message, 3);
        printColorful("1 -> Gostaria de gerenciar propriedades.\n", 5);
        printColorful("2 -> Gostaria de gerenciar contratos.\n", 5);
        printColorful("3 -> Gostaria de sair da minha conta.\n", 1);
        
        printColorful("Escolha uma opção: ", 5);
        scanf("%d", &option);
        
        if(option < 1 || option > 3){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 3);
    cleanScreen();
    return option;
}

void ownerMenuChoose(){
    switch (ownerMenu())
    {
        case 1:
        residenceManagerMenuChoose();
        break;
        
        case 2:
        contractManagerMenuChoose();
        break;

        case 3:
        logoutAuthUser();
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}