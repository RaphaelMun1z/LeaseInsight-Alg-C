#include <stdio.h>
#include <conio.h>

// Utils
#include "../../../utils/cleanScreen/cleanScreen.h"
#include "../../../utils/printColorful/printColorful.h"

// Views
#include "../homeMenu/homeMenu.h"
#include "../registerMenu/registerMenu.h"

// Controllers
#include "../../../controllers/registerController/registerController.h"
#include "../../../controllers/signInController/signInController.h"

int mainMenu(){
    int option;
    do{
        printColorful("\nComo posso ajudar? \n", 3);
        printColorful("1 -> Gostaria de me registrar.\n", 5);
        printColorful("2 -> Gostaria de acessar o sistema.\n", 5);
        printColorful("3 -> Gostaria de sair do sistema.\n", 1);
        
        option = getch();
        option -= '0';
        
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
        case 1:
        registerMenuChoose();
        return 1;
        break;
        
        case 2:
        signInForm();
        return 1;
        break;
        
        case 3:
        printColorful("\nAté mais!\n", 0);
        return 0;
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        return 1;
        break;
    }
}