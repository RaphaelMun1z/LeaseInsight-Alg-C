#ifndef CONTRACT_H
#define CONTRACT_H

// DTOs
#include "../../dtos/dtos.h"

extern Contract *contracts;
extern int registeredContractsNumber;
extern int contractsCurrentLimit;

void initContracts();
void allocateMoreSpaceContract();
void deallocateSpaceContract();
void allocateSpaceContractForFile(int numberOfContracts);
void freeContracts();

#endif