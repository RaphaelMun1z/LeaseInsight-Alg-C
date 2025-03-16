#include <stdio.h>
#include <stdlib.h>

// Utils
#include "utils/cleanScreen/cleanScreen.h"
#include "utils/printColorful/printColorful.h"
#include "utils/cleanInputBuffer/cleanInputBuffer.h"

// Views
#include "views/startScreen/startScreen.h"
#include "views/menus/menuHandler/menuHandler.h"

// Entities
#include "entities/AuthUser/AuthUser.h"
#include "entities/Tenant/Tenant.h"
#include "entities/Residence/Residence.h"
#include "entities/Contract/Contract.h"

// Controllers
#include "controllers/registerController/registerController.h"
#include "controllers/signInController/signInController.h"

int main(){
    cleanScreen();
    
    initAuthUser();
    initTenants();
    initResidences();
    initContracts();
    
    startScreen();
    
    printColorful("Seja bem-vindo(a)!\n\n", 2);
    
    int notFinished = 1;
    do{
        notFinished = redirectToMenu();
    } while(notFinished);
    
    freeTenants();
    freeResidences();
    freeContracts();

    cleanInputBuffer();
    printColorful("\n\nPressione qualquer tecla para fechar...", 5);
    getchar();

    return 0;
}