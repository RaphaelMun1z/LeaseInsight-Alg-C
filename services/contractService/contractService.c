#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/Contract/Contract.h"

// Services
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"

void findAllContracts(){
  if(contractsLength == 0)
    return printColorful("Não há contratos registrados.\n", 4);
    
    for (int ii = 0; ii < contractsLength; ii++){
        printf("\nID: %.0lf\n", contracts[ii].id);
        printf("Status: %d\n", contracts[ii].contractStatus);
        printf("Valor do aluguel: %.2lf\n", contracts[ii].defaultRentalValue);
        printf("Data de início: %s\n", contracts[ii].contractStartDate);
        printf("Data de término: %s\n", contracts[ii].contractEndDate);
        printf("Dia de vencimento: %d\n", contracts[ii].invoiceDueDate);
        printf("\n____\n");
    }
    
}

Contract *findContractById(double id){
    
}

void createContract(Contract contract){
    
}
void changeContractStatus(double id, int status){

}
