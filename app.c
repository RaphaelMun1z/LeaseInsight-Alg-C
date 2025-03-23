#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utils
#include "utils/cleanScreen/cleanScreen.h"
#include "utils/printColorful/printColorful.h"
#include "utils/cleanInputBuffer/cleanInputBuffer.h"

// Views
#include "views/startScreen/startScreen.h"
#include "views/menus/menuHandler/menuHandler.h"

// Entities
#include "entities/AuthUser/AuthUser.h"
#include "entities/Adm/Adm.h"
#include "entities/Tenant/Tenant.h"
#include "entities/Owner/Owner.h"
#include "entities/Residence/Residence.h"
#include "entities/Contract/Contract.h"

// Controllers
#include "controllers/registerController/registerController.h"
#include "controllers/signInController/signInController.h"

// Services
#include "services/dataPersistenceService/dataPersistenceService.h"

void initEntities(){
    initAuthUser();
    
    getAdmsData();    
    getTenantsData();
    getOwnersData();
    getResidencesData();
    getContractsData();
}

void freeEntities(){
    freeAdms();
    freeTenants();
    freeOwners();
    freeAuthUser();
    freeResidences();
    freeContracts();
}

void exitScreen(){
    cleanInputBuffer();
    printColorful("\nPressione enter para fechar...", 5);
    getchar();
}

int main(){
    // Criar Address para Residence - [é orbigatório por conta da pre entrega!]
    cleanScreen();
    
    initEntities();
    
    startScreen();
    printColorful("Seja bem-vindo(a)!\n", 0);
    
    initMenuHandler();
    
    freeEntities();
    
    exitScreen();    
    
    return 0;
}