#include <stdio.h>
#include <conio.h>
#include <string.h>

// Utils
#include "../../../utils/cleanScreen/cleanScreen.h"
#include "../../../utils/printColorful/printColorful.h"

// Entities
#include "../../../entities/AuthUser/AuthUser.h"

// Services
#include "../../../services/stateManagerService/stateManagerService.h"

// Views
#include "./usersManagerMenu/usersManagerMenu.h"
#include "./contractManagerAdmMenu/contractManagerAdmMenu.h"
#include "./residenceManagerAdmMenu/residenceManagerAdmMenu.h"

int admMenu(){
    int option;
    do{
        char message[100], name[100];
        (getAuthUserName() != NULL) ? strcpy(name, getAuthUserName()) : strcpy(name, "Não foi possível carregar.");
        snprintf(message, sizeof(message), "\n%s, de que forma posso auxiliar? \n", name);
        printColorful(message, 3);
        printColorful("1 -> Gostaria de gerenciar propriedades.\n", 5);
        printColorful("2 -> Gostaria de gerenciar contratos.\n", 5);
        printColorful("3 -> Gostaria de gerenciar usuários.\n", 5);
        printColorful("4 -> Gostaria de sair da minha conta.\n", 1);
        
        option = getch();
        option -= '0';
        
        if(option < 1 || option > 4){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 4);
    cleanScreen();
    return option;
}

void admMenuChoose(){
    switch (admMenu())
    {
        case 1:
        residenceManagerAdmMenuChoose();
        break;
        
        case 2:
        contractManagerAdmMenuChoose();
        break;

        case 3:
        usersManagerMenuChoose();
        break;
        
        case 4:
        logoutAuthUser();
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}