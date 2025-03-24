#include <stdio.h>

// Utils
#include "../../../utils/cleanScreen/cleanScreen.h"
#include "../../../utils/printColorful/printColorful.h"

// Controllers
#include "../../../controllers/registerController/registerController.h"

int registerMenu(){
    int option;
    do{
        printColorful("\nQual tipo de conta você gostaria de criar? \n", 3);
        printColorful("1 -> Voltar.\n", 6);
        printColorful("2 -> Registrar-me como INQUILINO\n", 5);
        printColorful("3 -> Registrar-me como PROPRIETÁRIO.\n", 5);
        
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

int registerMenuChoose(){
    switch (registerMenu())
    {
        case 1:
        return 0;
        break;

        case 2:
        registerTenantForm();
        return 1;
        break;
        
        case 3:
        registerOwnerForm();
        return 1;
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        return 1;
        break;
    }
}