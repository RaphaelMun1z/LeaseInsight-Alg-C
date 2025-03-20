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
#include "services/admService/admService.h"

void initEntities(){
    initAuthUser();
    initAdms();
    initTenants();
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
    printColorful("\nPressione qualquer tecla para fechar...", 5);
    getchar();
}

void mockRegisterAdm(){
    Adm adm;
    strcpy(adm.email, "teste@gmail.com");
    strcpy(adm.name, "irineu");
    strcpy(adm.password, "teste123");
    createAdm(adm);
}

int main(){
    // Falta completar o servico de criação de contrato (nesse momento o service de encontrar Residence pelo id nao existe)
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