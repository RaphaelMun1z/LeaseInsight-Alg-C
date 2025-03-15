#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    /* Tenant *tenants = (Tenant *) calloc(5, sizeof(Tenant));
    Residence *residences = (Residence *) calloc(5, sizeof(Residence));
    Contract *contracts = (Contract *) calloc(5, sizeof(Contract)); */
    
    cleanScreen();
    startScreen();
    
    printColorful("Seja bem-vindo(a)!\n\n", 2);
    
    int notFinished = 1;
    do{
        notFinished = mainMenuChoose();
    } while(notFinished);
    
    return 0;
}