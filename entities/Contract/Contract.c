#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double id;
    int contractStatus;
    double defaultRentalValue;
    int invoiceDueDate;
    char contractStartDate[11];
    char contractEndDate[11];
} Contract;

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