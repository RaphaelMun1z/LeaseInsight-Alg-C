#include <stdio.h>
#include <stdlib.h>

// DTOs
#include "../../dtos/dtos.h"

// Entities
#include "../../entities/GenericUser/GenericUser.h"

Owner *owners;
int registeredOwnersNumber = 0;
int ownersCurrentLimit = 5;

void initOwners() {
    owners = (Owner *) calloc(5, sizeof(Owner));
    
    if (owners == NULL) {
        printf("[LOG] Erro ao alocar memória para 'owners'!\n");
        return;
    }

    printf("[LOG] Memória padrão alocada para 'owners'\n");
}

void allocateSpaceOwnerForFile(int numberOfOwners){
    registeredUsersNumber += numberOfOwners;
    registeredOwnersNumber = numberOfOwners;
    ownersCurrentLimit = ((numberOfOwners / 5) + 1) * 5;

    owners = (Owner *) calloc(ownersCurrentLimit, sizeof(Owner));
    
    if (owners == NULL) {
        printf("[LOG] Erro ao alocar memória para 'owners'!\n");
        return;
    }

    printf("[LOG] Memória alocada para 'owners' com base nos %d registros do arquivo!\n", numberOfOwners);
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