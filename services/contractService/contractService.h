#ifndef CONTRACT_SERVICE_H
#define CONTRACT_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void printContract(Contract c);
void findAllContracts();
Contract *findContractById(double id);
void printContractById(double id);
void createContract(Contract contract); 
void changeContractStatus(double id, int status);

void findContractsByOwner(double id);

#endif