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
    if(authUser == NULL)
    return NULL;
    
    if(authUser->id == -1 || authUser->userType == -1)
    return NULL;
    
    return authUser;
}

char* getAuthUserName(){ 
    static char name[100]; 
    
    if(getAuthUser() == NULL)
    return NULL;
    
    if(getAuthUser()->userType == 3){
        Tenant *tenant = findTenantById(getAuthUser()->id);
        strcpy(name, tenant->name);
        return name;
    }
    
    return NULL;
}

void setAuthUser(char name[], AuthUser user){
    allocateAuthUserMemory(user.id, user.userType);
    
    char message[100];
    snprintf(message, sizeof(message), "\nLogado como %s. \n", name);
    printColorful(message, 2);
}

void removeAuthUser(){
    deallocateAuthUserMemory();
    
    printColorful("\nVocê saiu da sua conta!\n", 0);
}