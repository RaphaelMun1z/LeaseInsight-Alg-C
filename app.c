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
#include "services/admService/admService.h"

void initEntities(){
    initAuthUser();
    initAdms();
    
    getTenantsData();

    initOwners();
    initResidences();
    initContracts();
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

void mockRegisterAdm(){
    Adm adm;
    strcpy(adm.email, "adm@gmail.com");
    strcpy(adm.name, "adm");
    strcpy(adm.password, "adm123");
    createAdm(adm);
}

int main(){
    // importante!!!
    // verificar se há algum contrato vinculado a residencia antes de remover
    cleanScreen();
    
    initEntities();
    
    startScreen();
    printColorful("Seja bem-vindo(a)!\n", 0);
    
    mockRegisterAdm();
    
    initMenuHandler();
    
    freeEntities();
    
    exitScreen();    
    
    return 0;
}