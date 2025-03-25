#ifndef CONTRACT_SERVICE_H
#define CONTRACT_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllContracts();
Contract *findContractById(int id);
void findContractsByTenantRg(char tenantRg[]);
void findContractsByTenant(int tenantId, Contract *foundContracts);
void findContractsByOwner(int id, Contract *foundContracts);
void findContractsByStartDate(char startDate[], Contract *foundContracts);
void findContractsByEndDate(char endDate[], Contract *foundContracts);
void findContractsByStatus(int contractStatus);
void createContract(Contract contract); 
void deleteContract(int id); 

void printContract(Contract c);
void printContractById(int id);
void printContractByOwner(int contractId, int ownerId);
void printContractsByTenant(int tenantId);
void printContractsByOwner(int ownerId);
int contractExistsById(int id);
int ownerHasThisContract(int contractId, int ownerId);
int getContractsAmountByStartDate(char startDate[]);
int getContractsAmountByEndDate(char endDate[]);
int getContractsAmountByTenant(int tenantId);
int getContractsAmountByOwner(int ownerId);
int isOwnerAssociatedToContract(int contractId, int ownerId);
void changeContractStatus(int id, int status);

#endif