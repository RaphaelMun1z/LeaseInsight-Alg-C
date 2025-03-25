#include <stdio.h>

// Utils
#include "../../../utils/cleanScreen/cleanScreen.h"
#include "../../../utils/printColorful/printColorful.h"
#include "../../../utils/verifyInputContent/verifyInputContent.h"

// Views
#include "../registerMenu/registerMenu.h"

// Controllers
#include "../../../controllers/registerController/registerController.h"
#include "../../../controllers/signInController/signInController.h"

int mainMenu(){
    int option;
    do{
        printColorful("\nComo posso ajudar? \n", 3);
        printColorful("1 -> Sair do sistema.\n", 1);
        printColorful("2 -> Registrar-me.\n", 5);
        printColorful("3 -> Acessar o sistema.\n", 5);
        
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

int mainMenuChoose(){
    switch (mainMenu()){
        case 1: {
            char opt;
            printColorful("Tem certeza que deseja sair do sistema? (S/N) ", 4);
            scanf(" %c", &opt);
            
            if(opt == 'S' || opt == 's'){
                cleanScreen();
                printColorful("\nAté mais!\n", 0);
                return 0;
            }
            break;
        }
        
        case 2:
        registerMenuChoose();
        return 1;
        break;
        
        case 3:
        signInForm();
        return 1;
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        return 1;
        break;
    }
}