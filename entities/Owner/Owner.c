#include <stdio.h>
#include <stdlib.h>

// DTOs
#include "../../dtos/dtos.h"

Owner *owners;
int registeredOwnersNumber = 0;
int ownersCurrentLimit = 5;

void initOwners() {
    owners = (Owner *) calloc(5, sizeof(Owner));
    
    if (owners == NULL) {
        printf("[LOG] Erro ao alocar memória para 'owners'!\n");
    }
}

void allocateMoreSpaceOwner(){
    ownersCurrentLimit += 5;
    
    Owner *temp = realloc(owners, sizeof(Owner) * ownersCurrentLimit);
    if (temp == NULL){
        printf("[LOG] Erro ao realocar memória para 'owners'!\n");
        ownersCurrentLimit -= 5;
        return;
    }
    
    owners = temp;
}

void freeOwners(){
    free(owners);
    owners = NULL;
}