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
#include "entities/Owner/Owner.h"
#include "entities/Residence/Residence.h"
#include "entities/Contract/Contract.h"

// Controllers
#include "controllers/registerController/registerController.h"
#include "controllers/signInController/signInController.h"

void initEntities(){
    initAuthUser();
    initTenants();
    initOwners();
    initResidences();
    initContracts();
}

void freeEntities(){
    freeTenants();
    freeOwners();
    freeAuthUser();
    freeResidences();
    freeContracts();
}

void exitScreen(){
    cleanInputBuffer();
    printColorful("\nPressione qualquer tecla para fechar...", 5);
    getchar();
}

int main(){
    // Erros:
    // Não apareçe o nome do Owner no menu
    cleanScreen();
    
    initEntities();
    
    startScreen();
    printColorful("Seja bem-vindo(a)!\n", 0);
    initMenuHandler();
    
    freeEntities();
    
    exitScreen();    
    
    return 0;
}