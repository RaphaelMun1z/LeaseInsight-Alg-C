#ifndef CONTRACT_SERVICE_H
#define CONTRACT_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllContracts();
Contract *findContractById(double id);
void changeContractStatus(double id, int status);
void createContract(Contract contract); 

#endif