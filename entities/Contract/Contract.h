#ifndef CONTRACT_H
#define CONTRACT_H

// DTOs
#include "../../dtos/dtos.h"

extern Contract *contracts;
extern int contractsLength;
extern int contractsCurrentLimit;

void initContracts();
void allocateMoreSpaceContract();
void freeContracts();

#endif