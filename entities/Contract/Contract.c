#include <stdio.h>
#include <stdlib.h>

// DTOs
#include "../../dtos/dtos.h"

Contract *contracts;
int registeredContractsNumber = 0;
int contractsCurrentLimit;
const int contractIncrementAmount = 5;

void initContracts() {
    contractsCurrentLimit = 15;
    contracts = (Contract *) calloc(contractsCurrentLimit, sizeof(Contract));
    
    if (contracts == NULL) {
        printf("[LOG] Erro ao alocar memória para 'contracts'!\n");
        exit(1);
        return;
    }
    
    printf("[LOG] Memória padrão alocada para 'contracts'\n");
}

void allocateSpaceContractForFile(int numberOfContracts){
    registeredContractsNumber = numberOfContracts;
    contractsCurrentLimit = ((numberOfContracts / 5) + 1) * 5;
    
    contracts = (Contract *) calloc(contractsCurrentLimit, sizeof(Contract));
    
    if (contracts == NULL) {
        printf("[LOG] Erro ao alocar memória para 'contracts'!\n");
        exit(1);
        return;
    }
    
    printf("[LOG] Memória alocada para 'contracts' com base nos %d registros do arquivo!\n", numberOfContracts);
}

void allocateMoreSpaceContract() {
    int oldLimit = contractsCurrentLimit;
    contractsCurrentLimit += contractIncrementAmount;
    
    Contract *temp = (Contract *) realloc(contracts, sizeof(Contract) * contractsCurrentLimit);
    if (temp == NULL) {
        printf("[LOG] Erro ao realocar memória para 'contracts'!\n");
        contractsCurrentLimit = oldLimit;
        return;
    }
    
    contracts = temp;
    
    printf("[LOG] Espaço para mais contratos alocado com sucesso!\n");
}

void freeContracts(){
    free(contracts);
    contracts = NULL;
}