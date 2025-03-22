#ifndef CONTRACT_SERVICE_H
#define CONTRACT_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllContracts();
void findContractsByTenantRg(char tenantRg[]);
Contract *findContractById(double id);
void createContract(Contract contract); 
void deleteContract(double id); 

void printContract(Contract c);
void printContractById(double id);
int contractExistsById(double id);
void findContractsByOwner(double id);
void findContractsByTenant(double id);
void changeContractStatus(double id, int status);

#endif