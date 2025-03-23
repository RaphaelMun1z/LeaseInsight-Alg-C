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
        return;
    }
    
    for (int ii = 0; ii < contractsCurrentLimit; ii++) {
        contracts[ii].residence = (Residence *) calloc(1, sizeof(Residence));
        contracts[ii].tenant = (Tenant *) calloc(1, sizeof(Tenant));
        
        if (contracts[ii].residence == NULL || contracts[ii].tenant == NULL) {
            printf("[LOG] Erro ao alocar memória para 'contracts.residence' ou 'contracts.tenant'\n");
            return;
        }
    }
    
    printf("[LOG] Memória padrão alocada para 'contracts'\n");
}

void allocateSpaceContractForFile(int numberOfContracts){
    registeredContractsNumber = numberOfContracts;
    contractsCurrentLimit = ((numberOfContracts / 5) + 1) * 5;
    
    contracts = (Contract *) calloc(contractsCurrentLimit, sizeof(Contract));
    
    if (contracts == NULL) {
        printf("[LOG] Erro ao alocar memória para 'contracts'!\n");
        return;
    }
    
    for (int ii = 0; ii < contractsCurrentLimit; ii++) {
        contracts[ii].residence = (Residence *) calloc(1, sizeof(Residence));
        contracts[ii].tenant = (Tenant *) calloc(1, sizeof(Tenant));
        
        if (contracts[ii].residence == NULL || contracts[ii].tenant == NULL) {
            printf("[LOG] Erro ao alocar memória para 'contracts.residence' ou 'contracts.tenant'\n");
            return;
        }
    }
    
    printf("[LOG] Memória alocada para 'contracts' com base nos %d registros do arquivo!\n", numberOfContracts);
}

void allocateMoreSpaceContract() {
    int oldLimit = contractsCurrentLimit;
    contractsCurrentLimit += contractIncrementAmount;
    
    Contract *temp = realloc(contracts, sizeof(Contract) * contractsCurrentLimit);
    if (temp == NULL) {
        printf("[LOG] Erro ao realocar memória para 'contracts'!\n");
        contractsCurrentLimit = oldLimit;
        return;
    }

    contracts = temp;

    for (int i = oldLimit; i < contractsCurrentLimit; i++) {
        contracts[i].residence = (Residence *) calloc(1, sizeof(Residence));
        contracts[i].tenant = (Tenant *) calloc(1, sizeof(Tenant));

        if (contracts[i].residence == NULL || contracts[i].tenant == NULL) {
            printf("[LOG] Erro ao alocar memória para 'contracts[%d]'\n", i);
            return;
        }
    }

    printf("[LOG] Espaço para mais contratos alocado com sucesso!\n");
}

void freeContracts(){
    free(contracts);
    contracts = NULL;
}