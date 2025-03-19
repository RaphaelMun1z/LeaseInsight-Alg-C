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

void initContracts() {
    contracts = (Contract *) calloc(5, sizeof(Contract));

    if (contracts == NULL) {
        printf("[LOG] Erro ao alocar memória para 'contracts'!\n");
    }
}

void freeContracts(){
    free(contracts);
    contracts = NULL;
}