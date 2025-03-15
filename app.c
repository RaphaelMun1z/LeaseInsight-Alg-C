#include <stdio.h>
#include <stdlib.h>

// Utils
#include "utils/cleanScreen/cleanScreen.h"
#include "utils/printColorful/printColorful.h"
#include "utils/cleanInputBuffer/cleanInputBuffer.h"

// Views
#include "views/menus/mainMenu/mainMenu.h"
#include "views/startScreen/startScreen.h"

// Entities
#include "entities/Tenant/Tenant.h"
#include "entities/Residence/Residence.h"
#include "entities/Contract/Contract.h"

// Controllers
#include "controllers/registerController/registerController.h"
#include "controllers/signInController/signInController.h"

int main(){
    cleanScreen();
    
    initTenants();
    initResidences();
    initContracts();

    startScreen();
    
    printColorful("Seja bem-vindo(a)!\n\n", 2);
    
    int notFinished = 1;
    do{
        notFinished = mainMenuChoose();
    } while(notFinished);
    
    return 0;
}