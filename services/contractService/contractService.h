#ifndef CONTRACT_SERVICE_H
#define CONTRACT_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllContracts();
void findContractsByTenantRg(char tenantRg[]);
Contract *findContractById(int id);
void findContractsByStartDate(char startDate[], Contract *foundContracts);
void findContractsByEndDate(char endDate[], Contract *foundContracts);
void createContract(Contract contract); 
void deleteContract(int id); 

void printContract(Contract c);
void printContractById(int id);
int contractExistsById(int id);
void findContractsByOwner(int id);
void findContractsByTenant(int id);
int getContractsAmountByStartDate(char startDate[]);
int getContractsAmountByEndDate(char endDate[]);
void findContractsByStatus(int contractStatus);
void changeContractStatus(int id, int status);

#endif