#include <stdio.h>
#include <string.h>

// Utils
#include "../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../utils/printColorful/printColorful.h"
#include "../../../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../../../utils/verifyInputContent/verifyInputContent.h"

// Entities
#include "../../../../entities/AuthUser/AuthUser.h"

// Services
#include "../../../../services/stateManagerService/stateManagerService.h"

// Views
#include "./tenantManagerAdmMenu/tenantManagerAdmMenu.h"
#include "./ownerManagerAdmMenu/ownerManagerAdmMenu.h"

int usersManagerMenu(){
    int option;
    do{
        printColorful("Gerenciando usuários. Você pode: \n", 3);
        printColorful("1 -> Voltar.\n", 6);
        printColorful("2 -> Gerenciar inquilinos.\n", 5);
        printColorful("3 -> Gerenciar proprietários.\n", 5);
        
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

void usersManagerMenuChoose(){
    switch (usersManagerMenu())
    {
        case 1: {
            break;
        }

        case 2:
        tenantManagerAdmMenuChoose();
        usersManagerMenuChoose();
        break;
        
        case 3:
        ownerManagerAdmMenuChoose();
        usersManagerMenuChoose();
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}