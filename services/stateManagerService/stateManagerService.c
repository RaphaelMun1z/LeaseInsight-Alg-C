#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// DTOs
#include "../../dtos/dtos.h"

// Entities
#include "../../entities/AuthUser/AuthUser.h"

// Services
#include "../tenantService/tenantService.h"

AuthUser *getAuthUser(){
    if(authUser->id == -1 || authUser->userType == -1)
    return NULL;
    
    return authUser;
}

/* char* getAuthUserName() {
    char name[100];
    
    if(getAuthUser() == NULL)
    return NULL;
    
    if(getAuthUser()->userType == 3){
        Tenant *tenant = findTenantById(getAuthUser()->id);
        strcpy(name, tenant->name);
        return &name;
    }
    
    return NULL;
} */

char* getAuthUserName(){ 
    static char name[100] = "Olá mundo!"; 
    return name;
}

void setAuthUser(char name[], AuthUser user){
    authUser->id = user.id;
    authUser->userType = user.userType;
    
    char message[100];
    snprintf(message, sizeof(message), "\nLogado como %s. \n", name);
    printColorful(message, 2);
}

void removeAuthUser(){
    authUser->id = -1;
    authUser->userType = -1;
    freeAuthUser(authUser);
}