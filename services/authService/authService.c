#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// DTOs
#include "../../dtos/dtos.h"

// Entities
#include "../../entities/Tenant/Tenant.h"
#include "../../entities/Owner/Owner.h"

// Services
#include "../stateManagerService/stateManagerService.h"
#include "../tenantService/tenantService.h"
#include "../ownerService/ownerService.h"

void signInTenant(LoginCredentials credentials, AuthUserResponse *userResponse){
    Tenant *tenant = findTenantByEmail(credentials.email);
    
    if(tenant == NULL){
        userResponse = NULL;
        return;
    }
    
    if(strcmp(credentials.password, tenant->password) != 0){
        userResponse = NULL;
        return;
    }
    
    userResponse->id = tenant->id;
    userResponse->userType = 3;
    strcpy(userResponse->name, tenant->name);
}

void signInOwner(LoginCredentials credentials, AuthUserResponse *userResponse){
    Owner *owner = findOwnerByEmail(credentials.email);
    
    if(owner == NULL){
        userResponse = NULL;
        return;
    }
    
    if(strcmp(credentials.password, owner->password) != 0){
        userResponse = NULL;
        return;
    }
    
    userResponse->id = owner->id;
    userResponse->userType = 2;
    strcpy(userResponse->name, owner->name);
}

void signInUser(LoginCredentials credentials){
    AuthUserResponse possibleUser;
    possibleUser.id = -1;
    
    signInTenant(credentials, &possibleUser);
    if(possibleUser.id != -1){
        setAuthUser(possibleUser);
        return;
    }
    
    signInOwner(credentials, &possibleUser);
    if(possibleUser.id != -1){
        setAuthUser(possibleUser);
        return;
    }
    
    printColorful("Credenciais inválidas!\n", 1);
}