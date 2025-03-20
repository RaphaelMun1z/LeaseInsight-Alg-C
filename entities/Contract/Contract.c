#include <stdio.h>
#include <stdlib.h>

// DTOs
#include "../../dtos/dtos.h"

Contract *contracts;
int contractsLength = 0;
int contractsCurrentLimit = 5;

void initContracts() {
    contracts = (Contract *) calloc(5, sizeof(Contract));

    if (contracts == NULL) {
        printf("[LOG] Erro ao alocar memória para 'contracts'!\n");
    }
}

void allocateMoreSpaceContract(){
    contractsCurrentLimit += 5;
    
    Contract *temp = realloc(contracts, sizeof(Contract) * contractsCurrentLimit);
    if (temp == NULL){
        printf("[LOG] Erro ao realocar memória para 'contracts'!\n");
        contractsCurrentLimit -= 5;
        return;
    }
    
    contracts = temp;
}

void freeContracts(){
    free(contracts);
    contracts = NULL;
}