#include <stdio.h>
#include <stdlib.h>

// DTOs
#include "../../dtos/dtos.h"

AuthUser *authUser;

void initAuthUser() {
    authUser = (AuthUser *) calloc(1, sizeof(AuthUser));
    
    if (authUser == NULL) {
        printf("[LOG] Erro ao alocar memória para 'authUser'!\n");
        return;
    }
    
    authUser->id = -1;
    authUser->userType = -1;
}

// Ao realizar login
void allocateAuthUserMemory(){

}

// Ao realizar logout
void deallocateAuthUserMemory(){
    
}

// Usar apenas ao fechar app
void freeAuthUser(){
    free(authUser);
    authUser = NULL;
}

// Alterar esquema de alocação de memória, ideia: desalocar memoria ao sair da conta, 
// e alocar memoria ao realizar login