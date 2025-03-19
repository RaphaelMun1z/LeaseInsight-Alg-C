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
#include "../ownerService/ownerService.h"
#include "../admService/admService.h"

AuthUser *getAuthUser(){
    if(authUser == NULL)
    return NULL;
    
    if(authUser->id == -1 || authUser->userType == -1)
    return NULL;
    
    return authUser;
}

char *getAuthUserName(){ 
    AuthUser *user = getAuthUser();
    static char name[100]; 
    
    if(user == NULL)
    return NULL;
    
    if(user->userType == 3){
        Tenant *tenant = findTenantById(user->id);
        strcpy(name, tenant->name);
        return name;
    }

    if(user->userType == 2){
        Owner *owner = findOwnerById(user->id);
        strcpy(name, owner->name);
        return name;
    }

    if(user->userType == 1){
        Adm *adm = findAdmById(user->id);
        strcpy(name, adm->name);
        return name;
    }
    
    return NULL;
}

void setAuthUser(AuthUserResponse user){   
    if(authUser == NULL){
        printf("[LOG] 'authUser' não tem espaço alocado!\n");
        return;
    }
    
    authUser->id = user.id;
    authUser->userType = user.userType;
    
    char message[100], level[100] = "Não foi possível carregar.";
    
    if(user.userType == 1) strcpy(level, "Administrador");
    else if(user.userType == 2) strcpy(level, "Proprietário");
    else if(user.userType == 3) strcpy(level, "Inquilino");
    else strcpy(level, "Erro ao carregar.");
    
    snprintf(message, sizeof(message), "=== %s ===\n", level);
    printColorful(message, 5);
}

void logoutAuthUser(){
    authUser->id = -1;
    authUser->userType = -1;
    printColorful("\nVocê saiu da sua conta!\n", 0);
}