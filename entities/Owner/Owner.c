#include <stdio.h>
#include <stdlib.h>

// DTOs
#include "../../dtos/dtos.h"

// Entities
#include "../../entities/GenericUser/GenericUser.h"

Owner *owners;
int registeredOwnersNumber = 0;
int ownersCurrentLimit;
const int ownerIncrementAmount = 5;

void initOwners() {
    int ownersCurrentLimit = 15;
    owners = (Owner *) calloc(5, sizeof(Owner));
    
    if (owners == NULL) {
        printf("[LOG] Erro ao alocar memória para 'owners'!\n");
        return;
    }
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

    printf("[LOG] Espaço para mais proprietários alocado com sucesso!\n");
}

void deallocateSpaceOwner(){
    printf("Desalocando 5 espaços de memória para 'owners'\n");
    ownersCurrentLimit -= ownerIncrementAmount;
    
    Owner *temp = realloc(owners, sizeof(Owner) * ownersCurrentLimit);
    if (temp == NULL){
        printf("[LOG] Erro ao desalocar memória para 'owners'!\n");
        ownersCurrentLimit += ownerIncrementAmount;
        return;
    }
    
    owners = temp;
    printf("[LOG] Menos memória alocada para 'owners'\n");
}

void freeOwners(){
    free(owners);
    owners = NULL;
}