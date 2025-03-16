#include <stdio.h>
#include <stdlib.h>

// DTOs
#include "../../dtos/dtos.h"

AuthUser *authUser;

void setDefaultValuesToAuthUser(double id, int userType){
    if (authUser == NULL){
        printf("[LOG] Erro ao definir valores para 'authUser'!\n");
        return; 
    }
    
    authUser->id = id;
    authUser->userType = userType;
}

void allocateAuthUserMemory(double id, int userType){
    authUser = (AuthUser *) calloc(1, sizeof(AuthUser));
    
    if (authUser == NULL){
        printf("[LOG] Erro ao alocar memória para 'authUser'!\n");
        return; 
    }
    
    setDefaultValuesToAuthUser(id, userType);
}

void initAuthUser() {
    allocateAuthUserMemory(-1, -1);
}

void freeAuthUser(){
    free(authUser);
    authUser = NULL;
}

void deallocateAuthUserMemory(){
    freeAuthUser();
}