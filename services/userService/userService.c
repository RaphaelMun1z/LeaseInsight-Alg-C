#include <stdio.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Services
#include "../tenantService/tenantService.h"
#include "../ownerService/ownerService.h"
#include "../admService/admService.h"

int userAlreadyRegistered(char email[]){
    if(findOwnerByEmail(email) != NULL || findTenantByEmail(email) != NULL || findAdmByEmail(email) != NULL){
        printColorful("E-mail já cadastrado!\n", 1);
        return 1;
    }

    return 0;
}