#include <stdio.h>
#include <string.h>

// Utils
#include "../../../utils/cleanScreen/cleanScreen.h"
#include "../../../utils/printColorful/printColorful.h"
#include "../../../utils/verifyInputContent/verifyInputContent.h"

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
        printColorful("1 -> Sair da minha conta.\n", 6);
        printColorful("2 -> Gerenciar PROPRIEDADES.\n", 5);
        printColorful("3 -> Gerenciar CONTRATOS.\n", 5);
        
        printColorful("Escolha uma opção: ", 5);
        option = returnValidInt();
        
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
        logoutAuthUser();
        break;

        case 2:
        residenceManagerMenuChoose();
        break;
        
        case 3:
        contractManagerMenuChoose();
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}